#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <QDoubleSpinBox>
#include <QString>
#include <string>
#include <QStandardPaths>
#include <QDir>
#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->res_table->setColumnCount(3);
    ui->res_table->setHorizontalHeaderItem(0, new QTableWidgetItem("Time"));
    ui->res_table->setHorizontalHeaderItem(1, new QTableWidgetItem("Height"));
    ui->res_table->setHorizontalHeaderItem(2, new QTableWidgetItem("Speed"));
    connect(ui->Count_but, &QPushButton::clicked, this, &MainWindow::onCountClick);
    connect(ui->save_to_but, &QPushButton::clicked, this, &MainWindow::onSave_toClick);
}

double MainWindow::GetTS()
{
    return ts;
}

vector<vector<double>> MainWindow::GetVcount()
{
    return Vcount;
}

vector<vector<double>> MainWindow::GetScount()
{
    return Scount;
}

void MainWindow::SaveToFile(std::string FileName){
    QString downloadsPath = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    QString fullPath = QDir(downloadsPath).filePath(QString::fromStdString(FileName));
    ofstream file;
    int i=0;
    file.open(fullPath.toStdString(), ios::app);
    for (i = 0; i < Vcount.size(); i++)
    {
        file << Scount[i][0] << "," << Scount[i][1] << "," << Vcount[i][1] << endl;
    }
    file.close();
}

void MainWindow::Get_Solution(double g, double h, double V0, double H0, double Pmin, double Pmax, double m)
{
    double i, best_t = -1, best_P;
    vector<vector<double>> best_V, best_H;
    for (i = Pmin; i < Pmax; i+=100)
    {
        if ((i / m) < g)
        {
            continue;
        }
        Get_tfall(g, h, V0, H0, i, m);
        if (best_t < 0)
        {
            best_t = Vcount[Vcount.size() - 1][0];
            best_P = i;
            best_V = Vcount;
            best_H = Scount;
        }
        else
        {
            if (best_t > Vcount[Vcount.size() - 1][0])
            {
                best_t = Vcount[Vcount.size() - 1][0];
                best_P = i;
                best_V = Vcount;
                best_H = Scount;
            }
        }
    }
    Vcount = best_V;
    Scount = best_H;
}

void MainWindow::Get_tfall(double g, double h, double V0, double H0, double P, double m)
{
    double tfall; // ����� ������� ��� ���������
    int calculation_power = 1; // ����� ������� ���������� ts
    bool close_to_ans = false, past_crush = false; // ��� ������� ������ ����� �� ������� �������� ����������
    No_Engine_Run(g, h, V0, H0); // ������ ��� ������ ��������� (��� ����������� ������� �������)
    tfall = Scount[Scount.size() - 1][0];
    ts = tfall / 2;
    while (true) // ����� ts ����� ��������, ���� ���������
    {
        calculation_power += 1;
        Get_RK(g, P, m, h, V0, H0, ts);
        if ((abs(Vcount[Vcount.size() - 1][1]) < 5) && (Scount[Scount.size() - 1][1] <= 0)) // ���� �������� ��� ����������� � �������� ����������, ����������� ����������, ������� �� �����
        {
            break;
        }
        else
        {
            if (Scount[Scount.size() - 1][1] > H0) // ���� ��������� �� �����������, �������� ��������� �����
            {
                if (close_to_ans) // ���� ��� ����������� � ������ ts ������ �������, ������������ �� ���������� ��� � ����������� ��������
                {
                    ts += h;
                    h /= 2;
                }
                else
                {
                    if (past_crush)
                    {
                        ts += tfall / (pow(2, calculation_power-1));
                        close_to_ans = true;
                    }
                    else
                    {
                        ts += tfall / (pow(2, calculation_power));
                    }
                }
            }
            else // ���� �����������, �� ��������� ts, ���� �������� �� ����� � �������� ����������
            {
                if (close_to_ans)
                {
                    ts -= h;
                }
                else
                {
                    ts -= tfall / (pow(2, calculation_power));
                    past_crush = true;
                }
            }
        }
    }
}

void MainWindow::Get_RK(double g, double P, double m, double h, double V0, double H0, double t_start_engine)
{
    double t = 0;
    vector<double> Vc, Sc;
    Vcount.clear(); // Очищаем массивы V(t) и H(t) после прежыжущмх вычислений
    Scount.clear();
    Vc.push_back(t); // Задаем стартовые значения
    Vc.push_back(V0);
    Vcount.push_back(Vc);
    Sc.push_back(t);
    Sc.push_back(H0);
    Scount.push_back(Sc);
    while ((Scount[Scount.size() - 1][1] > 0) && (Scount[Scount.size() - 1][1] <= H0)) // Продолжаем пока не приземлимся или не начнем улетать
    {
        t += h;
        Sc.clear();
        Vc.clear();
        Sc.push_back(t);
        Vc.push_back(t);
        if (t < t_start_engine) // После момента включения двигателя меняем ускорение
        {
            Sc.push_back(Get_Sc(-g, h, V0, H0, t));
            Vc.push_back(Get_Vc(-g, h, V0, t));
        }
        else
        {
            Sc.push_back(Get_Sc(-g+(P/m), h, V0, H0, t));
            Vc.push_back(Get_Vc(-g+(P/m), h, V0, t));
        }
        Scount.push_back(Sc);
        Vcount.push_back(Vc);
    }
}

void MainWindow::No_Engine_Run(double g, double h, double V0, double H0)
{
    double t = 0;
    vector<double> Vc, Sc;
    Vcount.clear(); // Очищаем массивы V(t) и H(t) после предыдущмх вычислений
    Scount.clear();
    Vc.push_back(t); // Задаем стартовые значения
    Vc.push_back(V0);
    Vcount.push_back(Vc);
    Sc.push_back(t);
    Sc.push_back(H0);
    Scount.push_back(Sc);
    while (Scount[Scount.size() - 1][1] > 0)
    {
        t += h;
        Sc.clear();
        Sc.push_back(t);
        Sc.push_back(Get_Sc(-g, h, V0, H0, t));
        Scount.push_back(Sc);
        Vc.clear();
        Vc.push_back(t);
        Vc.push_back(Get_Vc(-g, h, V0, t));
        Vcount.push_back(Vc);
    }
}


double MainWindow::Get_Vc(double a, double h, double V0, double t)
{
    double k1, k2, k3, k4, Vpast, Vnew;
    int j;
    if (abs(Vcount[Vcount.size() - 1][0] - (t - h)) <= 0.00001)
    {
        Vpast = Vcount[Vcount.size() - 1][1];
        k1 = a;
        k2 = a;
        k3 = a;
        k4 = a;
        Vnew = Vpast + (h * (k1 + 2 * k2 + 2 * k3 + k4)) / 6;
        return Vnew;
    }
    else
    {
        if (abs(Vcount[Vcount.size() - 1][0] - t) <= 0.00001)
        {
            return Vcount[Vcount.size() - 1][1];
        }
    }
    for (j = 0; j < Vcount.size(); j++)
    {
        if (abs(Vcount[j][0] - t) <= 0.00001)
        {
            return Vcount[j][1];
        }
    }
    return 0.0f;
}

double MainWindow::Get_Sc(double a, double h, double V0, double S0, double t)
{
    double k1, k2, k3, k4, Spast, Snew;
    int j;
    if (abs(Scount[Scount.size() - 1][0] - (t - h)) <= 0.00001)
    {
        Spast = Scount[Scount.size() - 1][1];
        k1 = Get_Vc(a, h, V0, t - h);
        k2 = Get_Vc(a, h / 2, V0, t - (h / 2));
        k3 = k2;
        k4 = Get_Vc(a, h, V0, t);
        Snew = Spast + (h * (k1 + 2 * k2 + 2 * k3 + k4)) / 6;
        return Snew;
    }
    for (j = 0; j < Scount.size(); j++)
    {
        if (abs(Scount[j][0] - t) <= 0.00001)
        {
            return Scount[j][1];
        }
    }
    return 0.0f;
}

void MainWindow::onCountClick()
{
    // Очищаем таблицу перед новым расчетом
    ui->res_table->clearContents();
    ui->res_table->setRowCount(0);

    // Получаем параметры из интерфейса
    double g = ui->g_doubleSpinBox->value();
    double H0 = ui->H0_doubleSpinBox->value();
    double Pmin = ui->Pmin_doubleSpinBox->value();
    double Pmax = ui->Pmax_doubleSpinBox->value();
    double m = ui->m_doubleSpinBox->value();
    double h = 0.1;  // шаг по времени
    double V0 = 0;   // начальная скорость

    // Выполняем расчет
    Get_Solution(g, h, V0, H0, Pmin, Pmax, m);

    // Получаем результаты
    vector<vector<double>> V = GetVcount();
    vector<vector<double>> H = GetScount();

    // Проверяем, что данные есть
    if (V.empty() || H.empty() || V.size() != H.size())
    {
        QMessageBox::warning(this, "Ошибка",
                             "Расчет не выполнен или данные некорректны!\n"
                             "Проверьте входные параметры.");
        return;
    }

    // Устанавливаем количество строк
    ui->res_table->setRowCount(V.size());

    // Заполняем таблицу данными
    for (int i = 0; i < V.size(); i++)
    {
        // Время (секунды)
        QTableWidgetItem *timeItem = new QTableWidgetItem(
            QString::number(H[i][0], 'f', 3));  // 3 знака после запятой
        ui->res_table->setItem(i, 0, timeItem);

        // Высота (метры)
        QTableWidgetItem *heightItem = new QTableWidgetItem(
            QString::number(H[i][1], 'f', 3));
        ui->res_table->setItem(i, 1, heightItem);

        // Скорость (м/с)
        QTableWidgetItem *velocityItem = new QTableWidgetItem(
            QString::number(V[i][1], 'f', 3));
        ui->res_table->setItem(i, 2, velocityItem);
    }

    // Добавляем заголовки столбцов
    QStringList headers;
    headers << "Время (с)" << "Высота (м)" << "Скорость (м/с)";
    ui->res_table->setHorizontalHeaderLabels(headers);

    // Настраиваем отображение таблицы
    ui->res_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->res_table->verticalHeader()->setVisible(false);

    // Показываем статистику
    double finalTime = H.back()[0];
    double finalHeight = H.back()[1];
    double finalVelocity = V.back()[1];

    QString resultText = QString(
                             "Результаты посадки:\n"
                             "Время полета: %1 с\n"
                             "Финальная высота: %2 м\n"
                             "Финальная скорость: %3 м/с\n"
                             "Всего точек расчета: %4")
                             .arg(finalTime, 0, 'f', 2)
                             .arg(finalHeight, 0, 'f', 2)
                             .arg(finalVelocity, 0, 'f', 2)
                             .arg(V.size());

    // Выводим результат в statusBar или QLabel
    ui->statusbar->showMessage(resultText, 5000);

    // Или показываем в QMessageBox для наглядности
    if (abs(finalVelocity) < 5.0 && abs(finalHeight) < 0.1)
    {
        QMessageBox::information(this, "Успех!",
                                 "Мягкая посадка успешна!\n" + resultText);
    }
    else if (abs(finalVelocity) >= 5.0)
    {
        QMessageBox::critical(this, "Опасность!",
                              "Критическая скорость посадки!\n" + resultText);
    }
}
void MainWindow::onSave_toClick(){
    QString FileName = ui->FileName_line->text();
    SaveToFile(FileName.toStdString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

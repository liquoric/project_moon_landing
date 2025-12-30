#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <QDoubleSpinBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Count_but, &QPushButton::clicked, this, &MainWindow::onCountClick);
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

void MainWindow::Get_Solution(double g, double h, double V0, double H0, double P, double m)
{
    double tfall; // Время падения без двигателя
    int calculation_number = 1; // номер попытки вычисления ts
    bool close_to_ans = false; // при близком ответе может не хватать точности вычислений
    No_Engine_Run(g, h, V0, H0); // Прогон без работы двигателя (для определения времени падения)
    tfall = Scount[Scount.size() - 1][0];
    ts = tfall / 2;
    while (true) // Когда ts будет вычмслен, цикл прервется
    {
        calculation_number += 1;
        Get_RK(g, P, m, h, V0, H0, ts);
        if ((abs(Vcount[Vcount.size() - 1][1]) < 5) && (Scount[Scount.size()-1][1] <= 0)) // Если скорость при приземлении в пределах допустимой, заканчиваем вычисление, выходим из цикла
        {
            break;
        }
        else
        {
            if (Scount[Scount.size() - 1][1] > H0) // Если удаляемся от поверхности, включаем двигатель позже
            {
                if (close_to_ans) // Если при приближении к нужной ts начали улетать, возвращаемся на предыдущий шаг и увеличиваем точность
                {
                    ts += h;
                    h /= 2;
                }
                else
                {
                    ts += tfall / (pow(2, calculation_number));
                }
            }
            else // Если прилунились, то подбираем ts, пока скорость не будет в пределах допустимой
            {
                ts -= h;
                close_to_ans = true;
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

void MainWindow::onCountClick(){
    int i;
    QString solut = "";
    double g, h=0.1, V0=0, H0, P, m, ts;
    vector<vector<double>> V, H;
    g = ui->g_doubleSpinBox->value();
    H0 = ui->H0_doubleSpinBox->value();
    P = ui->P_doubleSpinBox->value();
    m = ui->m_doubleSpinBox->value();
    Get_Solution(g, h, V0, H0, P, m);
    ts = GetTS();
    V = GetVcount();
    H = GetScount();
    solut = solut.append(to_string(ts) + "\n");
    for (i = 0; i < V.size(); i++)
    {
        solut = solut.append(to_string(V[i][0]) + "\n");
        solut = solut.append(to_string(V[i][1]) + "\n");
        solut = solut.append(to_string(H[i][1]) + "\n");
    }
    ui->textEdit->setText(solut);
}

MainWindow::~MainWindow()
{
    delete ui;
}

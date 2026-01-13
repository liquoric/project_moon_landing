#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onCountClick();
    void onSave_toClick();
    void SaveToFile(std::string FileName);
    void Get_Solution(double g, double h, double V0, double H0, double Pmin, double Pmax, double m);
    void Get_tfall(double g, double h, double V0, double H0, double P, double m);
    double Get_Vc(double a, double h, double V0, double t);
    double Get_Sc(double a, double h, double V0, double S0, double t);
    void Get_RK(double g, double P, double m, double h, double V0, double H0, double t_start_engine);
    void No_Engine_Run(double g, double h, double V0, double H0);
    double GetTS();
    std::vector<std::vector<double>> GetVcount();
    std::vector<std::vector<double>> GetScount();
private:
    Ui::MainWindow *ui;
    double ts;
    std::vector<std::vector<double>> Vcount, Scount;
};
#endif // MAINWINDOW_H

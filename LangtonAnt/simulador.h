#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <QMainWindow>
#include <QGraphicsScene>
# include <QVector>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QTime>
#include <QtGlobal>
#include <QLabel>
#include "hormiga.h"
#include "imagen.h"
#include "grafica.h"

namespace Ui {
class SImulador;
}

class SImulador : public QMainWindow
{
    Q_OBJECT

public:
    explicit SImulador(QWidget *parent = 0); //Grid(QWidget *parent = 0);
    void armaArrays();
    void iniciaAlgoritmo();
    void delay(int seg);
    void saveFile();
    void pintaCelda(int x, int y, int c[3]);
    void pintaLineas(int robots);
    void repintaLineas();
    void agregaCasilla(int x, int y);
    void eliminaCasilla(int x, int y);
    int cuentaCasillas(int r, int g, int b);
    void actualizaGrid();

  //  void graficar(int generaciones, QVector <Hormiga*> ah);
    void graficar(int generaciones, QVector <Hormiga*> ah);

    Imagen *image;
    QVector <Hormiga*> ah;
    static bool inicia;
    ~SImulador();//~Grid();
     Ui::SImulador *ui;
     grafica *graph;
     QGraphicsScene *scene;
     QGraphicsPixmapItem *enemyItem;
     bool pausa;
     static int cg;
     bool reanuda;
     bool configuracion;
     bool inicializacion;
     bool maybeSave();
     int th;
     int escala;
     int r, g, b;
     int ractual, gactual, bactual;
     char p, pactual;
     int maximo;
     int step;
     int xInicial1;
     int xInicial2;
     int yInicial1;
     int yInicial2;
     char pInicial1;
     char pInicial2;
     int w;
     int retardo;
     int lineas;
     int fondo;
     int random;
     int densidad;
     int robots;


     QVector<QVector<int> > CasillasVisitadas;
     QVector<int> coo;

     QRgb rgbActual;
     QColor colorActual;
     QTime dieTime;
     QTime time;
     QThread t;
     QPixmap pm;


     QGraphicsItemGroup *gridLines;


public slots:

private slots:
     void on_startButton_clicked();
     void on_actionGrid_triggered();

     void on_pauseButton_clicked();

     void on_actionSave_configuration_triggered();

     void on_actionOpen_configuration_triggered();

    void on_actionDensities_triggered();


     void on_actionSave_image_triggered();

     void on_speedSlider_valueChanged(int value);

     void on_pickColor_clicked();

     void mousePressEvent(QMouseEvent *event);

     void on_actionInitialize_Configuration_triggered();

     void on_positionBox_highlighted(const QString &arg1);

     void on_zoomSlider_valueChanged(int value);

     void on_pushButton_clicked();

     void on_actionBackground_color_triggered();
     void on_actionRandom_inizialitation_triggered();
     void on_radioButton_clicked();

     void on_radioButton_2_clicked();

     void on_positionBox_activated(int index);

private:
     QString curFile;

};

#endif // SIMULADOR_H

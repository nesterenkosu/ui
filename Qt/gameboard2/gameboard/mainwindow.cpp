#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Инициализация флага создания поля "в первый раз"
    is_first=1;

    //Сделать вертикальный компоновочный виджет основным
    //в данном окне
    QWidget *w = new QWidget();
    w->setLayout(ui->verticalLayout);
    this->setCentralWidget(w);    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Определение размеров создаваемого поля
    //на основе значений, введённых пользователем в форму
    qint32 h = ui->le_H->text().toInt();
    qint32 w = ui->le_W->text().toInt();

    //Если поле создаётся не в первый раз
    if(is_first!=1) {
        delete(grid);//предварительно удалим старое поле
    }

    //Собственно создание поля
    //создание виджета табличной компоновки
    grid = new QGridLayout();

    grid->setSpacing(0);//убрать отступ между ячейками таблицы

    QPushButton *button;
    for(qint32 i=0;i<h;i++)
        for(qint32 j=0;j<w;j++){
            //создание клетки поля на основе кнопки
            button=new QPushButton(" ",this);
            //растянуть кнопку на всю ширину и высоту ячейки таблицы
            button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            //добавить кнопку в ячейку таблицы
            grid->addWidget(button,i,j);
            //добавить кнопку в ячейку таблицы
            connect(button,SIGNAL(clicked()),this,SLOT(on_gameboard_clicked()));
        }

    //добавить кнопку в ячейку таблицы
    ui->verticalLayout->addLayout(grid);

    //Обработка нажатия на кнопке - клетке игрового поля -
    //вывод знака * на нажатой кнопке
    is_first= 0;
}

void MainWindow::on_gameboard_clicked(){
    //Обработка нажатия на кнопке - клетке игрового поля -
    //вывод знака * на нажатой кнопке
    ((QPushButton* )QObject::sender())->setText("*");
}

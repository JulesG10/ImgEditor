#include "pixeldialog.h"
#include "ui_pixeldialog.h"
#include<QColorDialog>

PixelDialog::PixelDialog(QWidget *parent,QPixmap pixmap) :
    QDialog(parent),
    ui(new Ui::PixelDialog)
{
    ui->setupUi(this);
    this->ui->pushButton->setAutoDefault(false);
    this->ui->pushButton_2->setAutoDefault(true);
    this->pixmap = pixmap;
    this->ui->widget->setPixmap(this->pixmap);
    this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
}


bool PixelDialog::valide(QPixmap *pix)
{
    (*pix) = this->pixmap;
    return this->stop;
}

PixelDialog::~PixelDialog()
{
    delete ui;
}

void PixelDialog::on_pushButton_2_clicked()
{
    this->pixmap = this->ui->widget->getpixmap();
    this->stop = true;
    this->close();
}


void PixelDialog::on_pushButton_clicked()
{
    this->stop = false;
    this->close();
}


void PixelDialog::on_pushButton_3_clicked()
{
   this->pen_color = QColorDialog::getColor(Qt::white,this);
    this->ui->widget->setcolor(this->pen_color);
}


void PixelDialog::on_pushButton_4_clicked()
{
    this->pen_size++;
    if(this->pen_size > this->pixmap.width())
    {
        this->pen_size = this->pixmap.width();
    }
    this->ui->widget->setsize(this->pen_size);
    this->ui->label->setText("Taille du crayon: " + QString::number(this->pen_size));
}


void PixelDialog::on_pushButton_5_clicked()
{
    this->pen_size--;
    if(this->pen_size<0)
    {
        this->pen_size=0;
    }
    this->ui->widget->setsize(this->pen_size);
    this->ui->label->setText("Taille du crayon: " + QString::number(this->pen_size));
}


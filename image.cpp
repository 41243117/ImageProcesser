#include "image.h"
#include <QFileDialog>
#include <QDebug>

Image::Image(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(QStringLiteral("影像處理器"));
    central = new QWidget();
    mainLayout = new QHBoxLayout(central);
    imgWin = new QLabel();
    QPixmap *initPixmap = new QPixmap(300,200);
    initPixmap->fill(QColor(128,128,128));
    imgWin->resize(300,200);
    imgWin->setPixmap(*initPixmap);
    imgWin->setScaledContents(true);
    mainLayout->addWidget(imgWin);
    setCentralWidget(central);
    creatActions();
    creatMenus();
    creatToolBars();
}

Image::~Image() {}
void Image::creatActions(){
    openFileAction = new QAction(QStringLiteral("開啟檔案"),this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(QStringLiteral("開啟影像檔案"));
    exitAction = new QAction(QStringLiteral("結束"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(QStringLiteral("退出程式"));

    enlargeAction=new QAction(QStringLiteral("放大"),this);
    enlargeAction->setShortcut(tr("Ctrl+L"));
    enlargeAction->setStatusTip(QStringLiteral("放大影像"));
    shrinkAction=new QAction(QStringLiteral("縮小"),this);
    shrinkAction->setShortcut(tr("Ctrl+D"));
    shrinkAction->setStatusTip(QStringLiteral("縮小影像"));

    connect(openFileAction,SIGNAL(triggered()),this,SLOT(showOpenFile()));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
    connect(enlargeAction,SIGNAL(triggered()),this,SLOT(enlargeImage()));
    connect(shrinkAction,SIGNAL(triggered()),this,SLOT(shrinkImage()));
}

void Image::creatMenus()
{
    fileMenu = menuBar()->addMenu(QStringLiteral("檔案(&F)"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(exitAction);
    editMenu = menuBar()->addMenu(QStringLiteral("工具(&E)"));
    editMenu->addAction(enlargeAction);
    editMenu->addAction(shrinkAction);
}

void Image::creatToolBars()
{
    fileTool=addToolBar("file");
}

void Image::loadFile(QString filename)
{
    img.load(filename);
    imgWin->setPixmap(QPixmap::fromImage(img));
}

void Image::showOpenFile()
{
    filename=QFileDialog::getOpenFileName(this,QStringLiteral("開啟影像檔案"),tr("."),"all (*.*);;png (*.png);;jpg(*.jpg);;bmp (*.bmp)");
    if(!filename.isEmpty())
    {
        loadFile(filename);
    }
}

void Image::enlargeImage()
{
    QImage largeimg;
    largeimg = img.scaled(img.width()*2,img.height()*2);
    anotherWin.setPixmap(QPixmap::fromImage(largeimg));
    anotherWin.setScaledContents(true);
    anotherWin.show();
}

void Image::shrinkImage()
{
    QImage shrinkimg;
    shrinkimg = img.scaled(img.width()/2,img.height()/2);
    anotherWin.setPixmap(QPixmap::fromImage(shrinkimg));
    anotherWin.setScaledContents(true);
    anotherWin.show();
}
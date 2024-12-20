#ifndef IMAGE_H
#define IMAGE_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>

class Image : public QMainWindow
{
    Q_OBJECT

public:
    Image(QWidget *parent = nullptr);
    ~Image();
    void creatActions();
    void creatMenus();
    void creatToolBars();
    void loadFile(QString filename);

private slots:
    void showOpenFile();
    void enlargeImage();
    void shrinkImage();
private:
    QWidget  *central;
    QMenu    *fileMenu;
    QMenu    *editMenu;
    QToolBar *fileTool;
    QAction  *openFileAction;
    QAction  *exitAction;
    QAction  *enlargeAction;
    QAction  *shrinkAction;
    QImage    img;
    QLabel   *imgWin;
    QString   filename;
    QHBoxLayout *mainLayout;
    QLabel   anotherWin;
};
#endif // IMAGE_H

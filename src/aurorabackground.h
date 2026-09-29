 #ifndef AURORABACKGROUND_H
   #define AURORABACKGROUND_H

   #include <QWidget>
   #include <QPainter>
   #include <QTimer>

   class AuroraBackground : public QWidget {
       Q_OBJECT

   public:
       AuroraBackground(QWidget *parent = nullptr);
       ~AuroraBackground();

   protected:
       void paintEvent(QPaintEvent *event) override;

   private:
       void drawAurora(QPainter &painter);
   };

   #endif // AURORABACKGROUND_Hmanzini@fedora:~/ProjectFiles/C++Projects/manager/src$ 

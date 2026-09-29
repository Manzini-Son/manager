 #ifndef AURORABACKGROUND_H
   #define AURORABACKGROUND_H

   #include <QWidget>

   class AuroraBackground : public QWidget {
       Q_OBJECT

   public:
       explicit AuroraBackground(QWidget *parent = nullptr);
       void paintEvent(QPaintEvent *event) override;
   };

   #endif // AURORABACKGROUND_Hmanzini@fedora:~/ProjectFiles/C++Projects/manager/src$ 

#ifndef TIMERDIALOG_H
#define TIMERDIALOG_H

class TimerDialog;

#include <QDialog>
#include "boiltime.h"
#include "ui_timerDialog.h"
#include "TimerListDialog.h"
#ifndef NO_QTMULTIMEDIA
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPalette>
#endif

/*!
 * \class TimerDialog
 * \author Aidan Roberts
 *
 * \brief Individual boil addition timers
 */

class TimerDialog : public QDialog, public Ui::TimerDialog
{
    Q_OBJECT

public:
    TimerDialog(TimerListDialog *parent, BoilTime* bt = 0);
    ~TimerDialog();
    void setTime(int t);
    void setNote(QString n);
    void setBoil(BoilTime* bt);
    void reset();
    int getTime();
    void cancel();
    void hideTimer();
    void showTimer();

private slots:
    void on_setSoundButton_clicked();
    void on_setTimeBox_valueChanged(int t);
    void decrementTime();


    void on_stopButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::TimerDialog *ui;
    BoilTime* boilTime;
    bool started;
    bool stopped;
    unsigned int time;
    QPalette paletteOld, paletteNew;
    bool oldColors;
#ifndef NO_QTMULTIMEDIA
   QMediaPlayer* mediaPlayer;
   QMediaPlaylist* playlist;
#endif
   QByteArray timerPosition;

    void updateTime();
    void timesUp();
    QString timeToString(int t);
    void flash();
    void startAlarm();
    void setSound(QString s);
    void setDefualtAlarmSound();
    TimerListDialog* mainTimer;


};

#endif // TIMERDIALOG_H

#ifndef ADORA_H
#define ADORA_H

#include <QtWidgets/QMainWindow>
#include "ui_Adora.h"

class GeneralSettingWidget;
class VideoSettingWidget;
class AudioSettingWidget;
class ImageSettingWidget;
class TimeLimitSettingWidget;
class WatermarkSettingWidget;
class WritingSettingWidget;
class LanguageSettingWidget;
class LicenseWidget;
class AboutWidget;
class MenuButton;
class RecordVideoDialog;

#include <qlist.h>

class Adora : public QMainWindow {
	Q_OBJECT

private:
	Ui::Adora ui;

public:	
	bool restart;

private:
	bool mousePressed;
	QPoint prev;

private:
	RecordVideoDialog *recordVideoDialog;

private:
	GeneralSettingWidget *generalSettingWidget;
	VideoSettingWidget *videoSettingWidget;
	AudioSettingWidget *audioSettingWidget;
	ImageSettingWidget *imageSettingWidget;
	TimeLimitSettingWidget *timeLimitSettingWidget;
	WatermarkSettingWidget *watermarkSettingWidget;
	WritingSettingWidget *writingSettingWidget;
	LanguageSettingWidget *languageSettingWidget;
	LicenseWidget *licenseWidget;
	AboutWidget *aboutWidget;


private:
	QList<MenuButton*> menuButtons;

public:
	Adora(QWidget *parent = nullptr);
	~Adora();

protected:
	virtual void closeEvent(QCloseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);

	private slots :
	void closeButtonClicked();
	void minimizeButtonClicked();
	void recordButtonClicked();
	void requestRestart();
	void recordVideoDialogFinished();


	void generalButtonClicked();
	void videoButtonClicked();
	void audioButtonClicked();
	void imageButtonClicked();
	void timeLimitButtonClicked();
	void watermarkButtonClicked();
	void writingButtonClicked();
	void languageButtonClicked();
	void licenseButtonClicked();
	void aboutButtonClicked();


private:
	void initPosition();
	void initMenuStackWidget();
	void initMenuButtons();
};

#endif // ADORA_H

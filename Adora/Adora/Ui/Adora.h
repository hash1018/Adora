
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
class LanguageSettingWidget;
class LicenseWidget;
class AboutWidget;
class MenuButton;

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
	GeneralSettingWidget *generalSettingWidget;
	VideoSettingWidget *videoSettingWidget;
	AudioSettingWidget *audioSettingWidget;
	ImageSettingWidget *imageSettingWidget;
	TimeLimitSettingWidget *timeLimitSettingWidget;
	WatermarkSettingWidget *watermarkSettingWidget;
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

	private slots :
	void closeButtonClicked();
	void minimizeButtonClicked();
	void recordButtonClicked();
	void requestRestart();


	void generalButtonClicked();
	void videoButtonClicked();


private:
	void initPosition();
	void initMenuStackWidget();
};

#endif // ADORA_H

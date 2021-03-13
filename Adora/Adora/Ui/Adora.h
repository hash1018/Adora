
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
	void menuListItemClicked(QListWidgetItem *item);
	void requestRestart();


private:
	void initPosition();
	void initMenuListWidget();
	void initMenuStackWidget();
};

#endif // ADORA_H

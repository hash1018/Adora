

#ifndef _RECORDVIDEODIALOG_H
#define _RECORDVIDEODIALOG_H

#include <qdialog.h>
#include "RecordVideo/Chain/RecordVideoChain.h"
#include "Base/Namespace.h"
#include "RecordVideo/Entity/EntityList.h"
#include "RecordVideo/Unredo/WritingUnredoStack.h"
#include "RecordVideo/WritingData.h"

class ControllerWidget;
class RecordStatusMode;
class ResizeRecordRectDelegate;
class CaptureImageDelegate;
class WritingMode;
class WritingCommand;
class VideoRecorder;
class Time;

class RecordVideoDialog : public QDialog, public RecordVideoChain {

	Q_OBJECT

	friend class RecordVideoRequestStrategy;
	friend class RecordVideoRequestChangeRecordStatusStrategy;
	friend class RecordVideoRequestKeyEventStrategy;
	friend class RecordVideoRequestChangeWritingModeStrategy;
	friend class RecordVideoRequestUnredoStrategy;
	friend class RecordVideoRequestWritingDeleteAllStrategy;
	friend class RecordVideoRequestMuteAudioStrategy;


private:
	VideoRecorder *videoRecorder;

private:
	QRect recordAreaRect;

private:
	ControllerWidget *controllerWidget;

private:
	RecordStatusMode *recordStatusMode;
	

private:
	ResizeRecordRectDelegate *resizeRecordRectDelegate;
	CaptureImageDelegate *captureImageDelegate;

private:
	WritingMode *writingMode;
	EntityList entityList;
	WritingUnredoStack unredoStack;
	WritingData writingData;

public:
	RecordVideoDialog(QWidget *parent = nullptr);
	~RecordVideoDialog();

	virtual void hide();
	void addCommand(WritingCommand *command);

signals:
	void recordVideoDialogClosed();

private:
	void changeRecordStatusMode(RecordStatus recordStatus);
	void changeWritingMode(WritingStatus writingStatus);

private:
	virtual void request(RecordVideoRequest *request);

private:
	void record();
	void quit();
	void pause();
	void stop();
	void resume();
	void capture();
	void undo();
	void redo();
	void muteAudio(const QString &deviceName, bool muted);

	private slots:
	void started();
	void paused();
	void stopped();
	void resumed();
	void timePassed(Time &time);

protected:
	virtual void keyPressEvent(QKeyEvent *event);
	virtual void paintEvent(QPaintEvent *event);
	virtual void resizeEvent(QResizeEvent *event);
	virtual void moveEvent(QMoveEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void closeEvent(QCloseEvent *event);


public:
	QRect getRecordBorderRect();
	inline const QRect& getRecordAreaRect() const { return this->recordAreaRect; }
	RecordStatus getRecordStatus();
	inline EntityList* const getEntityList() { return &(this->entityList); }
	inline QColor getColor(WritingStatus status) { return this->writingData.getColor(status); }
	inline int getWidth(WritingStatus status) { return this->writingData.getWidth(status); }
	WritingStatus getCurrentWritingMode();
	void setColor(WritingStatus status, const QColor &color);
	void setWidth(WritingStatus status, int width);

private:
	void loadGeometry();
	void saveGeometry();
};



#endif //_RECORDVIDEODIALOG_H

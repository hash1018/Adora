

#include "RecordPanel.h"

RecordPanel::RecordPanel(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	
	

	// ³ìÈ­Àü
	ui.timeLabel->hide();
	ui.resumeButton->hide();
	ui.pauseButton->hide();
	ui.stopButton->hide();
	

	/*// ³ìÈ­Áß
	ui.recordButton->hide();
	ui.quitButton->hide();
	ui.resumeButton->hide();
	*/


	/* //ÀÏ½ÃÁ¤Áö
	ui.recordButton->hide();
	ui.quitButton->hide();
	ui.pauseButton->hide();
	*/
	

	
}

RecordPanel::~RecordPanel() {

}

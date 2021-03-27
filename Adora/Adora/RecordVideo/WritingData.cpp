

#include "WritingData.h"
#include <qsettings.h>

WritingData::WritingData() {

	WritingData::Data *data = new WritingData::Data(WritingStatus::Pencil);
	this->list.append(data);

	data = new WritingData::Data(WritingStatus::Highlight);
	this->list.append(data);

	data = new WritingData::Data(WritingStatus::Line);
	this->list.append(data);

	data = new WritingData::Data(WritingStatus::ArrowLine);
	this->list.append(data);

	data = new WritingData::Data(WritingStatus::Numbering);
	this->list.append(data);

	data = new WritingData::Data(WritingStatus::WritingStatus_Circle);
	this->list.append(data);

	data = new WritingData::Data(WritingStatus::WritingStatus_Rectangle);
	this->list.append(data);

	data = new WritingData::Data(WritingStatus::WritingStatus_Triangle);
	this->list.append(data);
}

WritingData::~WritingData() {

	for (int i = 0; i < this->list.size(); i++)
		delete this->list.at(i);

	this->list.clear();
}


void WritingData::load() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("WritingData");

	WritingData::Data *data = this->list.at(this->getIndex(WritingStatus::Pencil));
	if (settings.contains("PencilColor") == true)
		data->color.setNamedColor(settings.value("PencilColor").toString());
	if (settings.contains("PencilWidth") == true)
		data->width = settings.value("PencilWidth").toInt();

	data = this->list.at(this->getIndex(WritingStatus::Highlight));
	if (settings.contains("HighlightColor") == true)
		data->color.setNamedColor(settings.value("HighlightColor").toString());
	if (settings.contains("HighlightWidth") == true)
		data->width = settings.value("HighlightWidth").toInt();

	data = this->list.at(this->getIndex(WritingStatus::Line));
	if (settings.contains("LineColor") == true)
		data->color.setNamedColor(settings.value("LineColor").toString());
	if (settings.contains("LineWidth") == true)
		data->width = settings.value("LineWidth").toInt();

	data = this->list.at(this->getIndex(WritingStatus::ArrowLine));
	if (settings.contains("ArrowLineColor") == true)
		data->color.setNamedColor(settings.value("ArrowLineColor").toString());
	if (settings.contains("ArrowLineWidth") == true)
		data->width = settings.value("ArrowLineWidth").toInt();

	data = this->list.at(this->getIndex(WritingStatus::Numbering));
	if (settings.contains("NumberingColor") == true)
		data->color.setNamedColor(settings.value("NumberingColor").toString());
	if (settings.contains("NumberingWidth") == true)
		data->width = settings.value("NumberingWidth").toInt();

	data = this->list.at(this->getIndex(WritingStatus::WritingStatus_Rectangle));
	if (settings.contains("RectangleColor") == true)
		data->color.setNamedColor(settings.value("RectangleColor").toString());
	if (settings.contains("RectangleWidth") == true)
		data->width = settings.value("RectangleWidth").toInt();

	data = this->list.at(this->getIndex(WritingStatus::WritingStatus_Circle));
	if (settings.contains("CircleColor") == true)
		data->color.setNamedColor(settings.value("CircleColor").toString());
	if (settings.contains("CircleWidth") == true)
		data->width = settings.value("CircleWidth").toInt();

	data = this->list.at(this->getIndex(WritingStatus::WritingStatus_Triangle));
	if (settings.contains("TriangleColor") == true)
		data->color.setNamedColor(settings.value("TriangleColor").toString());
	if (settings.contains("TriangleWidth") == true)
		data->width = settings.value("TriangleWidth").toInt();

	

	settings.endGroup();
}

void WritingData::save() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("WritingData");
	
	WritingData::Data *data = this->list.at(this->getIndex(WritingStatus::Pencil));
	settings.setValue("PencilColor", data->color.name());
	settings.setValue("PencilWidth", data->width);

	data = this->list.at(this->getIndex(WritingStatus::Highlight));
	settings.setValue("HighlightColor", data->color.name());
	settings.setValue("HighlightWidth", data->width);

	data = this->list.at(this->getIndex(WritingStatus::Line));
	settings.setValue("LineColor", data->color.name());
	settings.setValue("LineWidth", data->width);

	data = this->list.at(this->getIndex(WritingStatus::ArrowLine));
	settings.setValue("ArrowLineColor", data->color.name());
	settings.setValue("ArrowLineWidth", data->width);

	data = this->list.at(this->getIndex(WritingStatus::Numbering));
	settings.setValue("NumberingColor", data->color.name());
	settings.setValue("NumberingWidth", data->width);

	data = this->list.at(this->getIndex(WritingStatus::WritingStatus_Triangle));
	settings.setValue("TriangleColor", data->color.name());
	settings.setValue("TriangleWidth", data->width);

	data = this->list.at(this->getIndex(WritingStatus::WritingStatus_Circle));
	settings.setValue("CircleColor", data->color.name());
	settings.setValue("CircleWidth", data->width);

	data = this->list.at(this->getIndex(WritingStatus::WritingStatus_Rectangle));
	settings.setValue("RectangleColor", data->color.name());
	settings.setValue("RectangleWidth", data->width);

	settings.endGroup();
}


QColor WritingData::getColor(WritingStatus status) {

	for (int i = 0; i < this->list.size(); i++) {
	
		if (this->list.at(i)->status == status) {
		
			return this->list.at(i)->color;
		}
	}

	return QColor();
}

int WritingData::getWidth(WritingStatus status) {

	for (int i = 0; i < this->list.size(); i++) {

		if (this->list.at(i)->status == status) {

			return this->list.at(i)->width;
		}
	}

	return 1;
}

void WritingData::setColor(WritingStatus status, const QColor &color) {

	for (int i = 0; i < this->list.size(); i++) {

		if (this->list.at(i)->status == status) {

			this->list.at(i)->color = color;
		}
	}
}

void WritingData::setWidth(WritingStatus status, int width) {

	for (int i = 0; i < this->list.size(); i++) {

		if (this->list.at(i)->status == status) {

			this->list.at(i)->width = width;
		}
	}
}


int WritingData::getIndex(WritingStatus status) {

	for (int i = 0; i < this->list.size(); i++) {
	
		if (this->list.at(i)->status == status) {
			return i;
		}
	}

	return -1;
}
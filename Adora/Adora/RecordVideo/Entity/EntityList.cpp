

#include "EntityList.h"

EntityList::EntityList()
	:Entity(QColor(),1) {

}

EntityList::~EntityList() {

	this->clear(true);
}

void EntityList::add(Entity *entity) {

	this->list.append(entity);
}

void EntityList::clear(bool deallocate) {

	if (deallocate == true) {

		while (!this->list.isEmpty())
			delete this->list.takeFirst();
	}
	else {

		this->list.clear();
	}
}

bool EntityList::remove(Entity *entity) {

	return this->list.removeOne(entity);
}
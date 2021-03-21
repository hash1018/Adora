

#ifndef _ENTITYLIST_H
#define _ENTITYLIST_H

#include "Entity.h"
#include <qlinkedlist.h>

class EntityList : public Entity {

private:
	QLinkedList<Entity*> list;

public:
	EntityList();
	~EntityList();

	virtual void accept(Visitor *visitor) {}

public:
	void add(Entity *entity);
	void clear(bool deallocate = false);
	bool remove(Entity *entity);

public:
	inline int getSize() const { return this->list.size(); }
	inline QLinkedList<Entity*>::iterator begin() { return this->list.begin(); }
	inline QLinkedList<Entity*>::iterator end() { return this->list.end(); }

};

#endif //_ENTITYLIST_H
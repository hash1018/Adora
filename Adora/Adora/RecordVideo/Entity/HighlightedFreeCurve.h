

#ifndef _HIGHLIGHTEDFREECURVE_H
#define _HIGHLIGHTEDFREECURVE_H

#include "FreeCurve.h"

class HighlightedFreeCurve : public FreeCurve {

protected:
	int alpha;

public:
	HighlightedFreeCurve(const QColor &color, int width, int alpha);
	~HighlightedFreeCurve();

	virtual void accept(Visitor *visitor);

public:
	void setAlpha(int alpha) { this->alpha = alpha; }

	inline int getAlpha() const { return this->alpha; }

};


#endif //_HIGHLIGHTEDFREECURVE_H
/*
   Tsunami for KallistiOS ##version##

   label.cpp

   Copyright (C) 2002 Megan Potter
*/

#include <plx/list.h>
#include "drawables/label.h"

Label::Label(Font * fh, const char *text, int size, bool centered, bool smear) {
	m_fh = fh;
	m_text = text;
	m_size = size;
	m_centered = centered;
	m_smear = smear;

}
Label::~Label() {
}

void Label::setText(const char * text) {
	m_text = text;
}

void Label::setFont(Font * f) {
	m_fh = f;
}

void Label::draw(int list) {
	if (list != PLX_LIST_TR_POLY)
		return;

	const Vector & p = getPosition();
	Color t = getColor();

	m_fh->setSize(m_size);
	m_fh->setAlpha(t.a);
	m_fh->setColor(t.r, t.g, t.b);
	if (m_centered) {
		if (m_smear)
			m_fh->smearDrawCentered(p.x, p.y, p.z, m_text);
		else
			m_fh->drawCentered(p.x, p.y, p.z, m_text);
	} else {
		if (m_smear)
			m_fh->smearDraw(p.x, p.y, p.z, m_text);
		else
			m_fh->draw(p.x, p.y, p.z, m_text);
	}
}

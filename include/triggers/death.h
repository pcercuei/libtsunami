/*
   Tsunami for KallistiOS ##version##

   death.h

   Copyright (C) 2002 Megan Potter

*/

#ifndef __TSUNAMI_TRIG_DEATH_H
#define __TSUNAMI_TRIG_DEATH_H

#include "../trigger.h"

class Death : public Trigger {
public:
	// Constructor / Destructor
	Death(Drawable * target = NULL);
	virtual ~Death();

	virtual void trigger(Drawable *t, Animation *a);
private:
	RefPtr<Drawable>	m_target;
};

#endif	/* __TSUNAMI_TRIG_DEATH_H */

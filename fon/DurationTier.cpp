/* DurationTier.cpp
 *
 * Copyright (C) 1992-2012,2015 Paul Boersma
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "DurationTier.h"

Thing_implement (DurationTier, RealTier, 0);

void structDurationTier :: v_info () {
	structDaata :: v_info ();
	MelderInfo_writeLine (U"Time domain:");
	MelderInfo_writeLine (U"   Start time: ", xmin, U" seconds");
	MelderInfo_writeLine (U"   End time: ", xmax, U" seconds");
	MelderInfo_writeLine (U"   Total original duration: ", xmax - xmin, U" seconds");
	MelderInfo_writeLine (U"Number of points: ", points -> size);
	MelderInfo_writeLine (U"Minimum relative duration value: ", RealTier_getMinimumValue (this));
	MelderInfo_writeLine (U"Maximum relative duration value: ", RealTier_getMaximumValue (this));
}

DurationTier DurationTier_create (double tmin, double tmax) {
	try {
		autoDurationTier me = Thing_new (DurationTier);
		RealTier_init (me.peek(), tmin, tmax);
		return me.transfer();
	} catch (MelderError) {
		Melder_throw (U"DurationTier not created.");
	}
}

void DurationTier_draw (DurationTier me, Graphics g, double tmin, double tmax,
	double ymin, double ymax, const char32 *method, int garnish)
{
	RealTier_draw (me, g, tmin, tmax, ymin, ymax, garnish, method, U"Relative duration");
}

DurationTier PointProcess_upto_DurationTier (PointProcess me) {
	try {
		autoDurationTier thee = DurationTier_create (my xmin, my xmax);
		for (long i = 1; i <= my nt; i ++) {
			RealTier_addPoint (thee.peek(), my t [i], 1.0);
		}
		return thee.transfer();
	} catch (MelderError) {
		Melder_throw (me, U": not converted to DurationTier.");
	}
}

/* End of file DurationTier.cpp */

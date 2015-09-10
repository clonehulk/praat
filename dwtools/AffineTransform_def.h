/* AffineTransform_def.h
 * 
 * Copyright (C) 1993-2008,2015 David Weenink
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#define ooSTRUCT AffineTransform
oo_DEFINE_CLASS (AffineTransform, Daata)

	oo_LONG (n)
	oo_DOUBLE_VECTOR (t, n)
	oo_DOUBLE_MATRIX (r, n, n)

	#if oo_DECLARING
		// new methods:
			virtual void v_transform (double **in, long nrows, double **out);
			virtual Any v_invert ();
	#endif

oo_END_CLASS(AffineTransform)
#undef ooSTRUCT


/* End of file AffineTransform_def.h */

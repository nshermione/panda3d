// Filename: lquaternion_src.h
// Created by:  frang (06Jun00)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://www.panda3d.org/license.txt .
//
// To contact the maintainers of this program write to
// panda3d@yahoogroups.com .
//
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//       Class : FLOATNAME(LQuaternion)
// Description : This is the base quaternion class
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA FLOATNAME(LQuaternion) : public FLOATNAME(LVecBase4) {
PUBLISHED:
  INLINE_LINMATH FLOATNAME(LQuaternion)();
  INLINE_LINMATH FLOATNAME(LQuaternion)(const FLOATNAME(LVecBase4) &copy);
  INLINE_LINMATH FLOATNAME(LQuaternion)(FLOATTYPE, FLOATTYPE, FLOATTYPE, FLOATTYPE);

  static FLOATNAME(LQuaternion) pure_imaginary(const FLOATNAME(LVector3) &);

  INLINE_LINMATH FLOATNAME(LVecBase3)
    xform(const FLOATNAME(LVecBase3) &v) const;

  INLINE_LINMATH FLOATNAME(LQuaternion)
    multiply(const FLOATNAME(LQuaternion) &rhs) const;

  INLINE_LINMATH FLOATNAME(LQuaternion) operator - () const;

  INLINE_LINMATH FLOATNAME(LQuaternion) operator *(const FLOATNAME(LQuaternion) &) const;
  INLINE_LINMATH FLOATNAME(LQuaternion)& operator *=(const FLOATNAME(LQuaternion) &);

  INLINE_LINMATH FLOATNAME(LMatrix3) operator *(const FLOATNAME(LMatrix3) &);
  INLINE_LINMATH FLOATNAME(LMatrix4) operator *(const FLOATNAME(LMatrix4) &);

  INLINE_LINMATH bool almost_equal(const FLOATNAME(LQuaternion) &, FLOATTYPE) const;
  INLINE_LINMATH bool almost_equal(const FLOATNAME(LQuaternion) &) const;

  INLINE_LINMATH void output(ostream&) const;

  void extract_to_matrix(FLOATNAME(LMatrix3) &m) const;
  void extract_to_matrix(FLOATNAME(LMatrix4) &m) const;

  void set_from_matrix(const FLOATNAME(LMatrix3) &m);
  INLINE_LINMATH void set_from_matrix(const FLOATNAME(LMatrix4) &m);
  void set_hpr(const FLOATNAME(LVecBase3) &hpr);
  FLOATNAME(LVecBase3) get_hpr() const;

  INLINE_LINMATH FLOATNAME(LVector3) get_axis() const;
  INLINE_LINMATH FLOATTYPE get_angle() const;

  INLINE_LINMATH FLOATTYPE get_r() const;
  INLINE_LINMATH FLOATTYPE get_i() const;
  INLINE_LINMATH FLOATTYPE get_j() const;
  INLINE_LINMATH FLOATTYPE get_k() const;

  INLINE_LINMATH void set_r(FLOATTYPE r);
  INLINE_LINMATH void set_i(FLOATTYPE i);
  INLINE_LINMATH void set_j(FLOATTYPE j);
  INLINE_LINMATH void set_k(FLOATTYPE k);

  INLINE_LINMATH bool normalize();

  INLINE_LINMATH bool invert_from(const FLOATNAME(LQuaternion) &other);
  INLINE_LINMATH bool invert_in_place();

  INLINE_LINMATH bool is_identity() const;
  INLINE_LINMATH static const FLOATNAME(LQuaternion) &ident_quat();

private:
  static const FLOATNAME(LQuaternion) _ident_quat;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type();
private:
  static TypeHandle _type_handle;
};


INLINE_LINMATH ostream& operator<<(ostream& os, const FLOATNAME(LQuaternion)& q) {
  q.output(os);
  return os;
}

BEGIN_PUBLISH
INLINE_LINMATH FLOATNAME(LQuaternion) invert(const FLOATNAME(LQuaternion) &a);
INLINE_LINMATH FLOATNAME(LMatrix3)
operator * (const FLOATNAME(LMatrix3) &m, const FLOATNAME(LQuaternion) &q);
INLINE_LINMATH FLOATNAME(LMatrix4)
operator * (const FLOATNAME(LMatrix4) &m, const FLOATNAME(LQuaternion) &q);
END_PUBLISH

#include "lquaternion_src.I"

#ifndef INPUTS_BOOST_SCOPED_PTR_H
#define INPUTS_BOOST_SCOPED_PTR_H

namespace boost {

template <class X> class scoped_ptr {
public:
  typedef X element_type;

  explicit scoped_ptr(X *p = 0) {}
  ~scoped_ptr() {}
};

}

#endif // INPUTS_BOOST_SCOPED_PTR_H

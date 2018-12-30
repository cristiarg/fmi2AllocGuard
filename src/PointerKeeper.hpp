#include <set>

class PointerKeeper
{
private: // types
  typedef std::set< void* > PointerToVoidSet_t;
  
public:
  PointerKeeper();
  ~PointerKeeper();

private:
  PointerKeeper(const PointerKeeper& );
    // intentially not implemented
  void operator=( const PointerKeeper& );
    // idem

public:
  bool add( void* _p );
  bool rem( void* _p );

  int flush();

private:
  PointerToVoidSet_t pointerToVoiSet;
};

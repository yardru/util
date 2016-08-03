#ifndef _ALLOCDBG_H_
#define _ALLOCDBG_H_

// memory allocation debug
#ifdef _DEBUG
#  define _CRTDBG_MAP_ALLOC
#  include <crtdbg.h>
#  define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
   // magic
#  define SetDbgMemHooks() \
  _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF | \
  _CRTDBG_ALLOC_MEM_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
    static class __Dummy
    {
    public:
      /* Class constructor */
      __Dummy()
      {
        SetDbgMemHooks();
      } /* End of '__Dummy' constructor */
    } __oops;
   // end of magic
#endif // _DEBUG

#endif // _ALLOCDBG_H_

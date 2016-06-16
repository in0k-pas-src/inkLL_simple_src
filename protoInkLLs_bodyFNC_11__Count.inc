{//.[ PRoTo Singly Linked Lists].....................[ in0k © 13.01.2013 ]...///
///                                                                          ///
///                                _____                                     ///
///                     +-+-+-+-+-|   __|_ _ first -> -                      ///
///                     |  PRoTo  |__   | | |         -                      ///
///                     +-+-+-+-+-|_____|_|_|         -                      ///
///                          v 2.0             nil <- =                      ///
///                                                                          ///
///............................................[ v 2.0 in0k © 27.05.2013 ]...//}
{%region /fold 'check "define" for all used macros'                      }
    //--- CONSTs
    {$if defined (_M_protoInkLLs_11__cstStopNODE)}
        {$define _cst_piLLs11_StopNODE:=_M_protoInkLLs_11__cstStopNODE}
    {$else}
        {$define _cst_piLLs11_StopNODE:=nil}
    {$endif}
    //--- VARs
    {$if defined (_M_protoInkLLs_11__cst_FIRST)}
        {$define _cst_piLLs11_FIRST:=_M_protoInkLLs_11__cst_FIRST}
    {$else}
        {$FATAL 'macro ".._cst_piLLs11_FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_11__out_COUNT)}
        {$define _out_piLLs11_COUNT:=_M_protoInkLLs_11__out_COUNT}
    {$else}
        {$FATAL 'macro ".._out_piLLs11_COUNT" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_11__lcl_getNext)}
        {$define _fnc_piLLs11_getNext:=_M_protoInkLLs_11__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLs11_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
{%endregion}
{%region /fold 'setUP local VARs'                                        }
{$if defined (_m_protoInkLLs_11__tmp_POINTER)}
    {$define _tmp_piLLs11_POINTER:=_m_protoInkLLs_11__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piLLs11_POINTER:=tmp}
{$endif}
{%endregion}
begin
   _out_piLLs11_COUNT:=0;
   _tmp_piLLs11_POINTER:=_cst_piLLs11_FIRST;
    while _tmp_piLLs11_POINTER<>_cst_piLLs11_StopNODE do begin
        inc(_out_piLLs11_COUNT);
       _tmp_piLLs11_POINTER:=_fnc_piLLs11_getNext(_tmp_piLLs11_POINTER);
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef SUPER local macros
    {$unDef _tmp_piLLs11_POINTER}
    //--- undef Local macros
    {$unDef _cst_piLLs11_FIRST}
    {$unDef _out_piLLs11_COUNT}
    {$unDef _fnc_piLLs11_getNext}
    //--- undef user
    {$undef _m_protoInkLLs_11__tmp_POINTER}
    {$undef _M_protoInkLLs_11__cstStopNODE}
    {$undef _M_protoInkLLs_11__cst_FIRST}
    {$undef _M_protoInkLLs_11__out_COUNT}
    {$unDef _M_protoInkLLs_11__lcl_getNext}
{%endregion}


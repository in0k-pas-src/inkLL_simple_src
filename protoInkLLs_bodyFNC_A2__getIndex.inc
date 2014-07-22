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
    //--- VARs
    {$if defined (_M_protoInkLLs_A2__cst_FIRST)}
        {$define _cst_piLLsA2_FIRST:=_M_protoInkLLs_A2__cst_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_A2__cst_NODE)}
        {$define _cst_piLLsA2_NODE:=_M_protoInkLLs_A2__cst_NODE}
    {$else}
        {$FATAL 'macro ".._NODE" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_A2__out_INDEX)}
        {$define _out_piLLsA2_INDEX:=_M_protoInkLLs_A2__out_INDEX}
    {$else}
        {$FATAL 'macro ".._INDEX" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_A2__out_RESULT)}
        {$define _out_piLLsA2_RESULT:=_M_protoInkLLs_A2__out_RESULT}
    {$else}
        {$FATAL 'macro ".._RESULT" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_A2__lcl_getNext)}
        {$define _fnc_piLLsA2_GetNext:=_M_protoInkLLs_A2__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLsA2_GetNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
{%region /fold 'setUP local VARs'                                        }
{$if defined (_m_protoInkLLs_A2__tmp_POINTER)}
    {$define _tmp_piLLsA2_POINTER:=_m_protoInkLLs_A2__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piLLsA2_POINTER:=tmp}
{$endif}
{%endregion}
begin
   _out_piLLsA2_RESULT :=false;
   _out_piLLsA2_INDEX  :=0;
   _tmp_piLLsA2_POINTER:=_cst_piLLsA2_FIRST;
    while (_tmp_piLLsA2_POINTER<>nil)and(_tmp_piLLsA2_POINTER<>_cst_piLLsA2_NODE) do begin
        inc(_out_piLLsA2_INDEX);
       _tmp_piLLsA2_POINTER:=_fnc_piLLsA2_GetNext(_tmp_piLLsA2_POINTER);
    end;
   _out_piLLsA2_RESULT:=(_tmp_piLLsA2_POINTER<>nil)and(_tmp_piLLsA2_POINTER=_cst_piLLsA2_NODE);
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Super Local macros
    {$unDef _tmp_piLLsA2_POINTER}
    //--- undef Local macros
    {$unDef _cst_piLLsA2_FIRST}
    {$unDef _cst_piLLsA2_NODE}
    {$unDef _out_piLLsA2_INDEX}
    {$unDef _out_piLLsA2_RESULT}
    {$unDef _fnc_piLLsA2_GetNext}
    //--- undef user macros
    {$unDef _m_protoInkLLs_A2__tmp_POINTER}
    {$unDef _M_protoInkLLs_A2__cst_FIRST}
    {$unDef _M_protoInkLLs_A2__cst_NODE}
    {$unDef _M_protoInkLLs_A2__out_INDEX}
    {$unDef _M_protoInkLLs_A2__out_RESULT}
    {$unDef _M_protoInkLLs_A2__lcl_getNext}
{%endregion 'unDEF used macros' /fold}


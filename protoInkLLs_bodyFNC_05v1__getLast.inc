{//.[ PRoTo Singly Linked Lists].....................[ in0k © 13.01.2013 ]...///
///                                                                          ///
///                                _____                                     ///
///                     +-+-+-+-+-|   __|_ _ first -> -                      ///
///                     |  PRoTo  |__   | | |         -                      ///
///                     +-+-+-+-+-|_____|_|_|         -                      ///
///                          v 2.0             nil <- =                      ///
///                                                                          ///
///............................................[ v 2.0 in0k © 27.05.2013 ]...//}
{%region /fold 'check "define" for all used macros                     ' }
    //--- VARs
    {$if defined (_M_protoInkLLs_05v1__cst_FIRST)}
        {$define _cst_piLLs05v1_FIRST:=_M_protoInkLLs_05v1__cst_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_05v1__out_LAST)}
        {$define _out_piLLs05v1_LAST:=_M_protoInkLLs_05v1__out_LAST}
    {$else}
        {$FATAL 'macro ".._LAST" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_05v1__lcl_getNext)}
        {$define _fnc_piLLs05v1_getNext:=_M_protoInkLLs_05v1__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLs05v1_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
begin
   _out_piLLs05v1_LAST:=_cst_piLLs05v1_FIRST;
    if _out_piLLs05v1_LAST<>nil then begin
        while _fnc_piLLs05v1_getNext(_out_piLLs05v1_LAST)<>nil do begin
           _out_piLLs05v1_LAST:=_fnc_piLLs05v1_getNext(_out_piLLs05v1_LAST);
        end;
    end;
end;
{%region /fold 'unDEF used macros                                      ' }
    //--- undef Local macros
    {$unDef _cst_piLLs05v1_FIRST}
    {$unDef _out_piLLs05v1_LAST}
    {$unDef _fnc_piLLs05v1_getNext}
    //--- undef user
    {$unDef _M_protoInkLLs_05v1__cst_FIRST}
    {$unDef _M_protoInkLLs_05v1__out_LAST}
    {$unDef _M_protoInkLLs_05v1__lcl_getNext}
{%endregion 'unDEF used macros' /fold}


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
    {$if defined (_M_protoInkLLs_05v2__cst_FIRST)}
        {$define _cst_piLLs05v2_FIRST:=_M_protoInkLLs_05v2__cst_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_05v2__out_COUNT)}
        {$define _out_piLLs05v2_COUNT:=_M_protoInkLLs_05v2__out_COUNT}
    {$else}
        {$FATAL 'macro ".._COUNT" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_05v2__out_LAST)}
        {$define _out_piLLs05v2_LAST:=_M_protoInkLLs_05v2__out_LAST}
    {$else}
        {$FATAL 'macro ".._LAST" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_05v2__lcl_getNext)}
        {$define _fnc_piLLs05v2_getNext:=_M_protoInkLLs_05v2__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLs05v2_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
{%endregion}
begin
   _out_piLLs05v2_COUNT:=0;
   _out_piLLs05v2_LAST :=nil;
    if _cst_piLLs05v2_FIRST<>nil then begin
       _out_piLLs05v2_COUNT:=1;
       _out_piLLs05v2_LAST :=_cst_piLLs05v2_FIRST;
        while _fnc_piLLs05v2_getNext(_out_piLLs05v2_LAST)<>nil do begin
            inc(_out_piLLs05v2_COUNT);
           _out_piLLs05v2_LAST:=_fnc_piLLs05v2_getNext(_out_piLLs05v2_LAST);
        end;
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Local macros
    {$unDef _cst_piLLs05v2_FIRST}
    {$unDef _out_piLLs05v2_COUNT}
    {$unDef _out_piLLs05v2_LAST}
    {$unDef _fnc_piLLs05v2_getNext}
    //--- undef user
    {$unDef _M_protoInkLLs_05v2__cst_FIRST}
    {$unDef _M_protoInkLLs_05v2__out_COUNT}
    {$unDef _M_protoInkLLs_05v2__out_LAST}
    {$unDef _M_protoInkLLs_05v2__lcl_getNext}
{%endregion}


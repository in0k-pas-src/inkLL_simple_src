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
    {$if defined (_M_protoInkLLs_20__cst_FIRST)}
        {$define _cst_piLLs20_FIRST:=_M_protoInkLLs_20__cst_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_20__cst_enumFNC)}
        {$define _fnc_piLLs20_enumFNC:=_M_protoInkLLs_20__cst_enumFNC}
    {$else}
        {$FATAL 'macro ".._enumFNC" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_20__cst_context)}
        {$define _cst_piLLs20_context:=_M_protoInkLLs_20__cst_context}
    {$else}
        {$FATAL 'macro ".._context" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_20__out_LAST)}
        {$define _out_piLLs20_LAST:=_M_protoInkLLs_20__out_LAST}
    {$else}
        {$FATAL 'macro ".._LAST" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_20__lcl_getNext)}
        {$define _fnc_piLLs20_getNext:=_M_protoInkLLs_20__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLs20_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
begin
   _out_piLLs20_LAST:=_cst_piLLs20_FIRST;
    while _out_piLLs20_LAST<>nil do begin
        {$if defined(_M_protoInkLLs_20__lcl_preENUM)}
            {$define _fnc_piLLs20_enumOBJ:=_M_protoInkLLs_20__lcl_preENUM(_out_piLLs20_LAST)}
        {$else}
            {$define _fnc_piLLs20_enumOBJ:=_out_piLLs20_LAST}
        {$endif}
        if _fnc_piLLs20_enumFNC(_cst_piLLs20_context,_fnc_piLLs20_enumOBJ)
        then _out_piLLs20_LAST:=_fnc_piLLs20_getNext(_out_piLLs20_LAST)
        else begin //< callBack просит ЗАВЕРШИТЬ обход
          {$if defined(_M_protoInkLLs_20__lcl_preENUM)}
           _out_piLLs20_LAST:=_fnc_piLLs20_enumOBJ;
          {$endif}
            break;
        end;
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Local macros
    {$unDef _cst_piLLs20_FIRST}
    {$unDef _cst_piLLs20_context}
    {$unDef _fnc_piLLs20_enumFNC}
    {$unDef _out_piLLs20_LAST}
    {$unDef _fnc_piLLs20_getNext}
    {$unDef _fnc_piLLs20_enumOBJ}
    //--- undef user
    {$unDef _M_protoInkLLs_20__cst_FIRST}
    {$unDef _M_protoInkLLs_20__cst_context}
    {$unDef _M_protoInkLLs_20__lcl_preENUM}
    {$unDef _M_protoInkLLs_20__cst_enumFNC}
    {$unDef _M_protoInkLLs_20__out_LAST}
    {$unDef _M_protoInkLLs_20__lcl_getNext}
{%endregion 'unDEF used macros' /fold}


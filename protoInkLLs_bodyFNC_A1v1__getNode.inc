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
    {$if defined (_M_protoInkLLs_A1v1__cst_FIRST)}
        {$define _cst_piLLsA1v1_FIRST:=_M_protoInkLLs_A1v1__cst_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_A1v1__var_INDEX)}
        {$define _var_piLLsA1v1_INDEX:=_M_protoInkLLs_A1v1__var_INDEX}
    {$else}
        {$FATAL 'macro ".._INDEX" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_A1v1__out_NODE)}
        {$define _out_piLLsA1v1_NODE:=_M_protoInkLLs_A1v1__out_NODE}
    {$else}
        {$FATAL 'macro ".._NODE" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_A1v1__lcl_getNext)}
        {$define _fnc_piLLsA1v1_getNext:=_M_protoInkLLs_A1v1__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLsA1v1_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
begin
   _out_piLLsA1v1_NODE:=_cst_piLLsA1v1_FIRST;
    while (_out_piLLsA1v1_NODE<>nil)and(_var_piLLsA1v1_INDEX>0) do begin
       _out_piLLsA1v1_NODE:=_fnc_piLLsA1v1_getNext(_out_piLLsA1v1_NODE);
        dec(_var_piLLsA1v1_INDEX);
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef SupreLocal macros
    {$unDef _cst_piLLsA1v1_FIRST}
    {$unDef _var_piLLsA1v1_INDEX}
    {$unDef _out_piLLsA1v1_NODE}
    {$unDef _fnc_piLLsA1v1_getNext}
    //--- undef user
    {$unDef _M_protoInkLLs_A1v1__cst_FIRST}
    {$unDef _M_protoInkLLs_A1v1__var_INDEX}
    {$unDef _M_protoInkLLs_A1v1__out_NODE}
    {$unDef _M_protoInkLLs_A1v1__lcl_getNext}
{%endregion 'unDEF used macros' /fold}


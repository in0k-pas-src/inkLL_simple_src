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
    {$if defined (_M_protoInkLLs_C1__var_FIRST)}
        {$define _var_piLLsC1_FIRST:=_M_protoInkLLs_C1__var_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_C1__out_NODE)}
        {$define _out_piLLsC1_NODE:=_M_protoInkLLs_C1__out_NODE}
    {$else}
        {$FATAL 'macro ".._NODE" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_C1__lcl_getNext)}
        {$define _fnc_piLLsC1_getNext:=_M_protoInkLLs_C1__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLsC1_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
{%endregion}
begin
   _out_piLLsC1_NODE :=_var_piLLsC1_FIRST;
   _var_piLLsC1_FIRST:=_fnc_piLLsC1_getNext(_out_piLLsC1_NODE);
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef SupreLocal macros
    {$unDef _var_piLLsC1_FIRST}
    {$unDef _out_piLLsC1_NODE}
    {$unDef _fnc_piLLsC1_getNext}
    //--- undef user
    {$unDef _M_protoInkLLs_C1__var_FIRST}
    {$unDef _M_protoInkLLs_C1__out_NODE}
    {$unDef _M_protoInkLLs_C1__lcl_getNext}
{%endregion}

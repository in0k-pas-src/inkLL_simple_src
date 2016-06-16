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
    {$if defined (_M_protoInkLLs_06__var_FIRST)}
        {$define _var_piLLs06_FIRST:=_M_protoInkLLs_06__var_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_06__cst_NODE)}
        {$define _cst_piLLs06_NODE:=_M_protoInkLLs_06__cst_NODE}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_06__lcl_setNext)}
        {$define _prc_piLLs06_setNext:=_M_protoInkLLs_06__lcl_setNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__SetNext)}
        {$define _prc_piLLs06_setNext:=_M_protoInkLLs_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
{%endregion}
begin
   _prc_piLLs06_setNext(_cst_piLLs06_NODE,_var_piLLs06_FIRST);
   _var_piLLs06_FIRST:=_cst_piLLs06_NODE;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Local macros
    {$unDef _var_piLLs06_FIRST}
    {$unDef _cst_piLLs06_NODE}
    {$unDef _prc_piLLs06_setNext}
    //--- undef user
    {$unDef _M_protoInkLLs_06__var_FIRST}
    {$unDef _M_protoInkLLs_06__cst_NODE}
    {$unDef _M_protoInkLLs_06__lcl_setNext}
{%endregion}


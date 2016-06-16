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
    {$if defined (_M_protoInkLLs_09v1__var_FIRST)}
        {$define _var_piLLs09v1_FIRST:=_M_protoInkLLs_09v1__var_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_09v1__cst_LIST)}
        {$define _cst_piLLs09v1_LIST:=_M_protoInkLLs_09v1__cst_LIST}
    {$else}
        {$FATAL 'macro ".._LIST" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_09v1__lcl_getNext)}
        {$define _fnc_piLLs09v1_getNext:=_M_protoInkLLs_09v1__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLs09v1_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_09v1__lcl_setNext)}
        {$define _prc_piLLs09v1_setNext:=_M_protoInkLLs_09v1__lcl_setNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__SetNext)}
        {$define _prc_piLLs09v1_setNext:=_M_protoInkLLs_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
{%endregion}
{%region /fold 'setUP local VARs'                                        }
{$if defined (_m_protoInkLLs_09v1__tmp_POINTER)}
    {$define _tmp_piLLs09v1_POINTER:=_m_protoInkLLs_09v1__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piLLs09v1_POINTER:=tmp}
{$endif}
{%endregion}
begin
    if _var_piLLs09v1_FIRST<>nil then begin
        //--- вспомогательный алгоритм
        {$ifDef inkLLsimple_fncHeadMessage}{$message 'inline -> protoInkLLs_bodyFNC_05v1__getLast'}{$endIF}
            {$deFine _M_protoInkLLs_05v1__cst_FIRST:=_var_piLLs09v1_FIRST}
            {$deFine _M_protoInkLLs_05v1__out_LAST :=_tmp_piLLs09v1_POINTER}
            {$I protoInkLLs_bodyFNC_05v1__getLast.inc}
        //--- основной алгоритм
        {$ifDef inkLLsimple_fncHeadMessage}{$message 'MAIN code'}{$endIF}
       _prc_piLLs09v1_setNext(_tmp_piLLs09v1_POINTER,_cst_piLLs09v1_LIST);
    end
    else _var_piLLs09v1_FIRST:=_cst_piLLs09v1_LIST;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Super Local macros
    {$unDef _tmp_piLLs09v1_POINTER}
    //--- undef SupreLocal macros
    {$unDef _var_piLLs09v1_FIRST}
    {$unDef _cst_piLLs09v1_LIST}
    {$unDef _fnc_piLLs09v1_getNext}
    {$unDef _prc_piLLs09v1_setNext}
    //--- undef user macros
    {$unDef _m_protoInkLLs_09v1__tmp_POINTER}
    {$unDef _M_protoInkLLs_09v1__var_FIRST}
    {$unDef _M_protoInkLLs_09v1__cst_LIST}
    {$unDef _M_protoInkLLs_09v1__lcl_getNext}
    {$unDef _M_protoInkLLs_09v1__lcl_setNext}
{%endregion}


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
    {$if defined (_M_protoInkLLs_08v2__var_FIRST)}
        {$define _var_piLLs08v2_FIRST:=_M_protoInkLLs_08v2__var_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_08v2__cst_NODE)}
        {$define _cst_piLLs08v2_NODE:=_M_protoInkLLs_08v2__cst_NODE}
    {$else}
        {$FATAL 'macro ".._NODE" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_08v2__out_COUNT)}
        {$define _out_piLLs08v2_COUNT:=_M_protoInkLLs_08v2__out_COUNT}
    {$else}
        {$FATAL 'macro ".._COUNT" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_08v2__lcl_getNext)}
        {$define _fnc_piLLs08v2_getNext:=_M_protoInkLLs_08v2__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLs08v2_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_08v2__lcl_setNext)}
        {$define _prc_piLLs08v2_setNext:=_M_protoInkLLs_08v2__lcl_setNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__SetNext)}
        {$define _prc_piLLs08v2_setNext:=_M_protoInkLLs_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
{%endregion}
{%region /fold 'setUP local VARs'                                        }
{$if defined (_m_protoInkLLs_08v2__tmp_POINTER)}
    {$define _tmp_piLLs08v2_POINTER:=_m_protoInkLLs_08v2__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piLLs08v2_POINTER:=tmp}
{$endif}
{%endregion}
begin
    //-- проверки
    {$ifOpt D+}
        {$if defined (_M_protoInkLLs_blockFNK__GetNext)}
            if _fnc_piLLs08v2_getNext(_cst_piLLs08v2_NODE)<>nil then begin
                raise Exception.CReate('_cst_piLLs08v2_NODE^.next<>nil !!!');
            end;
        {$endif}
    {$endif}
    //-- алгоРИТМ
    if _var_piLLs08v2_FIRST<>nil then begin
        //--- вспомогательный алгоритм
        {$ifDef inkLLsimple_fncHeadMessage}{$message 'inline -> protoInkLLs_bodyFNC_05v2__getLast'}{$endIF}
             {$deFine _M_protoInkLLs_05v2__cst_FIRST:=_var_piLLs08v2_FIRST}
             {$deFine _M_protoInkLLs_05v2__out_COUNT:=_out_piLLs08v2_COUNT}
             {$deFine _M_protoInkLLs_05v2__out_LAST :=_tmp_piLLs08v2_POINTER}
             {$I protoInkLLs_bodyFNC_05v2__getLast.inc}
        //--- основной алгоритм
        {$ifDef inkLLsimple_fncHeadMessage}{$message 'MAIN code'}{$endIF}
       _prc_piLLs08v2_setNext(_tmp_piLLs08v2_POINTER,_cst_piLLs08v2_NODE);
        inc(_out_piLLs08v2_COUNT);
    end
    else begin
       _var_piLLs08v2_FIRST:=_cst_piLLs08v2_NODE;
       _out_piLLs08v2_COUNT:=1;
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Super Local macros
    {$unDef _tmp_piLLs08v2_POINTER}
    //--- undef Local macros
    {$unDef _var_piLLs08v2_FIRST}
    {$unDef _cst_piLLs08v2_NODE}
    {$unDef _out_piLLs08v2_COUNT}
    {$unDef _fnc_piLLs08v2_getNext}
    {$unDef _prc_piLLs08v2_setNext}
    //--- undef user
    {$unDef _m_protoInkLLs_08v2__tmp_POINTER}
    {$unDef _M_protoInkLLs_08v2__var_FIRST}
    {$unDef _M_protoInkLLs_08v2__out_COUNT}
    {$unDef _M_protoInkLLs_08v2__cst_NODE}
    {$unDef _M_protoInkLLs_08v2__lcl_getNext}
    {$unDef _M_protoInkLLs_08v2__lcl_setNext}
{%endregion 'unDEF used macros' /fold}


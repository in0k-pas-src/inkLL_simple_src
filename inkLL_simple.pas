unit inkLL_simple;
{<*** Singly Linked Lists
    * библиокека для работы с "Простыми Связными Списками"
    *}
{//..................................................[ in0k © 13.01.2013 ]...///
///                                                                          ///
///                                _____                                     ///
///                     +-+-+-+-+-|   __|_ _ first -> -                      ///
///                     |  PRoTo  |__   | | |         -                      ///
///                     +-+-+-+-+-|_____|_|_|         -                      ///
///                          v 2.0             nil <- =                      ///
///                                                                          ///
///............................................[ v 2.0 in0k © 27.05.2013 ]...//}
{краткое содержание повествования:   //---------------------------------//

  #1 объявление типов
  ===================

     inkLL_node

  #2 работа со списком
  ====================

    -- 2.00-FF рождение и смерть
    00    - создание/инициализация
    --
    FF    - оЧистка/уничтожение
    FFx0  - очистка с уничтожением pQueueNode (вообще, это тока для тестов)
    FFx1  - очистка с вызовом-по-указателю функции
    FFx2  - очистка с вызовом-по-указателю МЕТОДА класса

    E4    - очистка узлов удовлетворяющих условию


    -- 2.2 текущие/очевидные свойства списка
    10    - проверка на пустоту
    11    - количесво узлов

    -- 2.3 от кончика ушей до пят (операции над ВСЕМ списком)
    20    - обход списка (с первого по последний)
    20x1  - обход списка с вызовом-по-указателю функции
    20x2  - обход списка вызовом-по-указателю МЕТОДА класса
    69    - инвертирование списка

    -- 2.5 последний Герой (последний узел списка)
    05v1  - последний Узел
    05v2  - последний Узел и общее кол-во узлов

    -- 2.6 вырезать "МЕНЯ"
    C0v1  - вырезать УЗЕЛ (САМОГО СЕБЯ)
    C0v2  - вырезать УЗЕЛ (САМОГО СЕБЯ) и подтверждение и вырезании

    -- 2.7 Грива и Хвост (вставка/удаление из начала и конца очереди)
    C1    - вырезать УЗЕЛ из Начала списка
    06    - вставить УЗЕЛ в начало списка
    07    - вставить СПИСОК в начало списка
    --
    CFv1  - вырезать УЗЕЛ из Конца списка
    CFv2  - вырезать УЗЕЛ из Конца списка
    08v1  - вставить УЗЕЛ в конец списка
    08v2  - вставить УЗЕЛ в конец списка и общее кол-во узлов
    09v1  - вставить СПИСОК в конец списка
    09v2  - вставить СПИСОК в конец списка и общее кол-во узлов

    -- 2.8 МАССИВ
    A1v1  - элемент с индексом
    A1v2  - элемент с индексом или ПОСЛЕДНИЙ
    A2    - индекс элемента (принадлежит ли элемент списку)
    --
    A3    - вставить элемент с индексом
    A4    - вставить СПИСОК с индексом
    --
    A5    - вырезать элемент с индексом
    A6    - вырезать СПИСОК с индексом

//---------------------------------------------------------------------------//}
interface
{%region /fold}//----------------------------------[ compiler directives ]
{}  {$ifdef fpc}                                             { это для LAZARUS }
{}     {$mode delphi}     // для пущей совместимости написанного кода         {}
{}     {$define _INLINE_}                                                     {}
{}  {$else}                                                   { это для DELPHI }
{}     {$IFDEF SUPPORTS_INLINE}                                               {}
{}       {$define _INLINE_}                                                   {}
{}     {$endif}                                                               {}
{}  {$endif}                                                                  {}
{}  {$ifOpt D+} // режим дебуга ВКЛЮЧЕН                      { "боевой" INLINE }
{}       {$undef _INLINE_} // дeбугить просче БЕЗ INLIN`а                     {}
{}  {$endif}                                                                  {}
{%endregion}//-------------------------------------------[ compiler directives ]
{$define _INLINE_}
{$ifOpt D+}
{$define inkLLsimple_fncHeadMessage} //< сообщения о текущей процедуре, с ними проще ловить ошибки
{$endif}
uses {$ifOpt D+}sysutils,{$endif}
    inkLL_node;

//****************************************************************************//
//                                                                            //
//                                                                   ЧАСТЬ #2 //
//                                                                            //
//****************************************************************************//

//== 2.0-F рождение и смерть ==

procedure inkLLs_INIT (out SLL:pointer);                                        {$ifdef _INLINE_} inline; {$endif}

procedure inkLLs_CLEAR(var SLL:pointer; disposePRC:fInkNodeLL_doDispose);       {$ifdef _INLINE_} inline; {$endif} overload;
procedure inkLLs_CLEAR(var SLL:pointer; disposePRC:aInkNodeLL_doDispose);       {$ifdef _INLINE_} inline; {$endif} overload;

procedure inkLLs_Erase(var SLL:pointer; const CmpCXT:pointer; const CmpFNC:fInkNodeLL_doProcess; const DspPRC:fInkNodeLL_doDispose); {$ifdef _INLINE_} inline; {$endif} overload;
procedure inkLLs_Erase(var SLL:pointer; const CmpCXT:pointer; const CmpFNC:fInkNodeLL_doProcess; const DspPRC:aInkNodeLL_doDispose); {$ifdef _INLINE_} inline; {$endif} overload;
procedure inkLLs_Erase(var SLL:pointer; const CmpCXT:pointer; const CmpFNC:aInkNodeLL_doProcess; const DspPRC:fInkNodeLL_doDispose); {$ifdef _INLINE_} inline; {$endif} overload;
procedure inkLLs_Erase(var SLL:pointer; const CmpCXT:pointer; const CmpFNC:aInkNodeLL_doProcess; const DspPRC:aInkNodeLL_doDispose); {$ifdef _INLINE_} inline; {$endif} overload;

//== 2.2 текущие/очевидные свойства списка ==

function  inkLLs_isEmpty(const SLL:pointer):boolean;                            {$ifdef _INLINE_} inline; {$endif}
function  inkLLs_Count  (const SLL:pointer):tInkLLNodeCount;                    {$ifdef _INLINE_} inline; {$endif}

//== 2.3 от кончика ушей до пят (операции над ВСЕМ списком) ==

function  inkLLs_Enumerate(const SLL:pointer; const Context:pointer; const EnumFNC:fInkNodeLL_doProcess):pointer; {$ifdef _INLINE_} inline; {$endif} overload;
function  inkLLs_Enumerate(const SLL:pointer; const Context:pointer; const EnumFNC:aInkNodeLL_doProcess):pointer; {$ifdef _INLINE_} inline; {$endif} overload;
procedure inkLLs_Invert   (var   SLL:pointer);                                  {$ifdef _INLINE_} inline; {$endif}

//== 2.5 последний Герой (последний узел списка) ==

function  inkLLs_getLast(const SLL:pointer):pointer;                            {$ifdef _INLINE_} inline; {$endif} overload;
function  inkLLs_getLast(const SLL:pointer; out Count:tInkLLNodeCount):pointer; {$ifdef _INLINE_} inline; {$endif} overload;
function  inkLLs_getLast(const SLL:pointer; out Last :pointer):tInkLLNodeCount; {$ifdef _INLINE_} inline; {$endif} overload;

//== 2.6 вырезать "МЕНЯ" ==

procedure inkLLs_cutNode   (var SLL:pointer; const Node:pointer);               {$ifdef _INLINE_} inline; {$endif} overload;
function  inkLLs_cutNodeRes(var SLL:pointer; const Node:pointer):boolean;       {$ifdef _INLINE_} inline; {$endif} overload;

//== 2.7 Грива и Хвост (вставка/удаление из начала и конца СПИСКА) ==

//=== Грива ===

function  inkLLs_cutNodeFirst(var SLL:pointer):pointer;                         {$ifdef _INLINE_} inline; {$endif}
procedure inkLLs_insNodeFirst(var SLL:pointer; const Node:pointer);             {$ifdef _INLINE_} inline; {$endif}
procedure inkLLs_insListFirst(var SLL:pointer; const List:pointer);             {$ifdef _INLINE_} inline; {$endif}

//=== Хвост ===

function  inkLLs_cutNodeLast(var SLL:pointer):pointer;                          {$ifdef _INLINE_} inline; {$endif} overload;
function  inkLLs_cutNodeLast(var SLL:pointer; out  Count:tInkLLNodeCount):pointer;{$ifdef _INLINE_} inline; {$endif} overload;
procedure inkLLs_insNodeLast(var SLL:pointer; const Node:pointer);              {$ifdef _INLINE_} inline; {$endif} overload;
procedure inkLLs_insNodeLast(var SLL:pointer; const Node:pointer; out Count:tInkLLNodeCount); {$ifdef _INLINE_} inline; {$endif} overload;
procedure inkLLs_insListLast(var SLL:pointer; const List:pointer);              overload; {$ifdef _INLINE_} inline; {$endif}
procedure inkLLs_insListLast(var SLL:pointer; const List:pointer; out Count:tInkLLNodeCount);            overload; {$ifdef _INLINE_} inline; {$endif}

//    == 2.8 МАССИВ ==

function  inkLLs_getNode      (const SLL:pointer; Index:tInkLLNodeIndex):pointer;                         {$ifdef _INLINE_} inline; {$endif}
function  inkLLs_getNodeOrLast(const SLL:pointer; Index:tInkLLNodeIndex):pointer;                         {$ifdef _INLINE_} inline; {$endif}
function  inkLLs_getIndex     (const SLL:pointer; const Node:pointer; out Index:tInkLLNodeIndex):boolean; {$ifdef _INLINE_} inline; {$endif}
procedure inkLLs_insNodeIndex (var   SLL:pointer; const Node:pointer; Index:tInkLLNodeIndex);             {$ifdef _INLINE_} inline; {$endif}
function  inkLLs_cutNodeIndex (var   SLL:pointer; Index:tInkLLNodeIndex):pointer;                         {$ifdef _INLINE_} inline; {$endif}

implementation

function inkNodeLLs_getNext(const node:pointer):pointer; {$ifdef _INLINE_} inline; {$endif}
begin
    result:=InkNodeLL_getNext(node);
end;

procedure inkNodeLLs_setNext(const node,next:pointer);   {$ifdef _INLINE_} inline; {$endif}
begin
    InkNodeLL_setNext(node,next);
end;

//****************************************************************************//
//                                                                            //
//                                                                   ЧАСТЬ #2 //
//                                                                            //
//****************************************************************************//

{$MACRO ON}
{$deFine _M_protoInkLLs_blockFNK__GetNext:=inkNodeLLs_getNext}
{$deFine _M_protoInkLLs_blockFNK__SetNext:=inkNodeLLs_setNext}
{.$deFine _M_protoInkLLs_blockFNK__nodeDST:=''} //< чтобы ПОМНИТЬ

//------------------------------------------------------------------------------

{:::[00] ИНИЦИАЛИЗИРОВАТЬ, подготовить к работе.
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  ---
  * SLL сделана как out для "подавления" hint`ов при начальной инициализации
  :}
procedure inkLLs_INIT(out SLL:pointer);
begin
    SLL:=nil;
end;

//------------------------------------------------------------------------------

{:::[FFx1] УНИЧТОЖИТЬ элементы списка по порядку с ПЕРВОГО по ПОСЛЕДНИЙ.
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(disposePRC указатель на ФУНКЦИЮ уничтожения узла)
  ---
  * после выполнения SLL===@nil
  :}
procedure inkLLs_CLEAR(var SLL:pointer; disposePRC:fInkNodeLL_doDispose);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_CLEAR function'}{$endIF}
var tmp:pointer;
{$deFine _m_protoInkLLs_FF__tmp_POINTER:=tmp}
{$deFine _M_protoInkLLs_FF__var_FIRST  :=SLL}
{$deFine _M_protoInkLLs_FF__lcl_nodeDST:=disposePRC}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_FF__CLEAR.inc}
end;

{:::[FFx2] УНИЧТОЖИТЬ элементы списка по порядку с ПЕРВОГО по ПОСЛЕДНИЙ.
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(disposePRC указатель на МЕТОД обЪекта уничтожения узла)
  ---
  * после выполнения SLL===@nil
  :}
procedure inkLLs_CLEAR(var SLL:pointer; disposePRC:aInkNodeLL_doDispose);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_CLEAR method'}{$endIF}
var tmp:pointer;
{$deFine _m_protoInkLLs_FF__tmp_POINTER:=tmp}
{$deFine _M_protoInkLLs_FF__var_FIRST  :=SLL}
{$deFine _M_protoInkLLs_FF__lcl_nodeDST:=disposePRC}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_FF__CLEAR.inc}
end;

//------------------------------------------------------------------------------

{:::[E4xff] УНИЧТОЖИТЬ элементы УДОВЛЕТВОРЯЮЩИЕ условию.
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(CmpCXT контекст для проверти узла)
  @param(CmpFNC callBack функция для проверки узла, если она возвращает TRUE, то кзел будет УНИЧТОЖЕН)
  @param(DspPRC callBack процедура УНИЧТОЖЕНИЯ узла)
  :}
procedure inkLLs_Erase(var SLL:pointer; const CmpCXT:pointer; const CmpFNC:fInkNodeLL_doProcess; const DspPRC:fInkNodeLL_doDispose);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_Erase xff'}{$endIF}
var tmp,tmq:pointer;
{$deFine _m_protoInkLLs_E4__tmp_POINTER0:=tmp}
{$deFine _m_protoInkLLs_E4__tmp_POINTER1:=tmq}
{$deFine _M_protoInkLLs_E4__var_FIRST   :=SLL}
{$deFine _M_protoInkLLs_E4__cst_cmpCTX  :=CmpCXT}
{$deFine _M_protoInkLLs_E4__cst_cmpFNC  :=CmpFNC}
{$deFine _M_protoInkLLs_E4__lcl_dspPRC  :=DspPRC}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_E4__Erase.inc}
end;

{:::[E4xfa] УНИЧТОЖИТЬ элементы УДОВЛЕТВОРЯЮЩИЕ условию.
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(CmpCXT контекст для проверти узла)
  @param(CmpFNC callBack функция для проверки узла, если она возвращает TRUE, то кзел будет УНИЧТОЖЕН)
  @param(DspPRC callBack процедура УНИЧТОЖЕНИЯ узла)
  :}
procedure inkLLs_Erase(var SLL:pointer; const CmpCXT:pointer; const CmpFNC:fInkNodeLL_doProcess; const DspPRC:aInkNodeLL_doDispose);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_Erase xfa'}{$endIF}
var tmp,tmq:pointer;
{$deFine _m_protoInkLLs_E4__tmp_POINTER0:=tmp}
{$deFine _m_protoInkLLs_E4__tmp_POINTER1:=tmq}
{$deFine _M_protoInkLLs_E4__var_FIRST   :=SLL}
{$deFine _M_protoInkLLs_E4__cst_cmpCTX  :=CmpCXT}
{$deFine _M_protoInkLLs_E4__cst_cmpFNC  :=CmpFNC}
{$deFine _M_protoInkLLs_E4__lcl_dspPRC  :=DspPRC}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_E4__Erase.inc}
end;

{:::[E4xaf] УНИЧТОЖИТЬ элементы УДОВЛЕТВОРЯЮЩИЕ условию.
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(CmpCXT контекст для проверти узла)
  @param(CmpFNC callBack функция для проверки узла, если она возвращает TRUE, то кзел будет УНИЧТОЖЕН)
  @param(DspPRC callBack процедура УНИЧТОЖЕНИЯ узла)
  :}
procedure inkLLs_Erase(var SLL:pointer; const CmpCXT:pointer; const CmpFNC:aInkNodeLL_doProcess; const DspPRC:fInkNodeLL_doDispose);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_Erase xaf'}{$endIF}
var tmp,tmq:pointer;
{$deFine _m_protoInkLLs_E4__tmp_POINTER0:=tmp}
{$deFine _m_protoInkLLs_E4__tmp_POINTER1:=tmq}
{$deFine _M_protoInkLLs_E4__var_FIRST   :=SLL}
{$deFine _M_protoInkLLs_E4__cst_cmpCTX  :=CmpCXT}
{$deFine _M_protoInkLLs_E4__cst_cmpFNC  :=CmpFNC}
{$deFine _M_protoInkLLs_E4__lcl_dspPRC  :=DspPRC}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_E4__Erase.inc}
end;

{:::[E4xaa] УНИЧТОЖИТЬ элементы УДОВЛЕТВОРЯЮЩИЕ условию.
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(CmpCXT контекст для проверти узла)
  @param(CmpFNC callBack функция для проверки узла, если она возвращает TRUE, то кзел будет УНИЧТОЖЕН)
  @param(DspPRC callBack процедура УНИЧТОЖЕНИЯ узла)
  :}
procedure inkLLs_Erase(var SLL:pointer; const CmpCXT:pointer; const CmpFNC:aInkNodeLL_doProcess; const DspPRC:aInkNodeLL_doDispose);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_Erase xaa'}{$endIF}
var tmp,tmq:pointer;
{$deFine _m_protoInkLLs_E4__tmp_POINTER0:=tmp}
{$deFine _m_protoInkLLs_E4__tmp_POINTER1:=tmq}
{$deFine _M_protoInkLLs_E4__var_FIRST   :=SLL}
{$deFine _M_protoInkLLs_E4__cst_cmpCTX  :=CmpCXT}
{$deFine _M_protoInkLLs_E4__cst_cmpFNC  :=CmpFNC}
{$deFine _M_protoInkLLs_E4__lcl_dspPRC  :=DspPRC}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_E4__Erase.inc}
end;

//------------------------------------------------------------------------------

{:::[10] очередь ПУСТая?
  @param (SLL переменная-ссылко-указатель на первый узел списка)
  @result(@true -- да, очередь Пуста; @false -- ЕСТЬ элементы)
  :}
function inkLLs_isEmpty(const SLL:pointer):boolean;
begin
    result:=SLL=nil;
end;

//------------------------------------------------------------------------------

{:::[11] ПОсчитать количество узлов (путем прямого перебора)
  @param (SLL переменная-ссылко-указатель на первый узел списка)
  @return(количество узлов)
  :}
function inkLLs_Count(const SLL:pointer):tInkLLNodeCount;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkSLL_Count'}{$endIF}
var tmp:pointer;
{$deFine _M_protoInkLLs_11__tmp_POINTER:=tmp}
{$deFine _M_protoInkLLs_11__cst_FIRST  :=SLL}
{$deFine _M_protoInkLLs_11__out_COUNT  :=result}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_11__Count.inc}
end;

//------------------------------------------------------------------------------

{:::[20x1] перечислить (посетить КАЖДЫЙ узел в порядке с ПЕРВОГО по ПОСЛЕДНИЙ)
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(enumData указатель на "информацию", передаваемую в enumFNC для каждого узла)
  @param(enumFNC указатель на "callBack" функцию, вызываемую для КАЖДОГО узла)
  @returns(@nil -- обошли ВСЮ очередь, иначе ссылка-указатель на последний посещенный узел)
  :}
function inkLLs_Enumerate(const SLL:pointer; const Context:pointer; const enumFNC:fInkNodeLL_doProcess):pointer;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_Enumerate function'}{$endIF}
{$deFine _M_protoInkLLs_20__cst_FIRST  :=SLL}
{$deFine _M_protoInkLLs_20__cst_context:=Context}
{$deFine _M_protoInkLLs_20__cst_enumFNC:=enumFNC}
{$deFine _M_protoInkLLs_20__out_LAST   :=result}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_20__Enumerate.inc}
end;

{:::[20x2] перечислить (посетить КАЖДЫЙ узел в порядке с ПЕРВОГО по ПОСЛЕДНИЙ)
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(enumData указатель на "информацию", передаваемую в enumFNC для каждого узла)
  @param(enumFNC указатель на "callBack" функцию, вызываемую для КАЖДОГО узла)
  @returns(@nil -- обошли ВСЮ очередь, иначе ссылка-указатель [pQueueNode] на последний посещенный узел)
  :}
function inkLLs_Enumerate(const SLL:pointer; const Context:pointer; const enumFNC:aInkNodeLL_doProcess):pointer;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_Enumerate method'}{$endIF}
{$deFine _M_protoInkLLs_20__cst_FIRST  :=SLL}
{$deFine _M_protoInkLLs_20__cst_context:=Context}
{$deFine _M_protoInkLLs_20__cst_enumFNC:=enumFNC}
{$deFine _M_protoInkLLs_20__out_LAST   :=result}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_20__Enumerate.inc}
end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

{:::[69] изменить порядок следования узлов списка на ОБРАТНЫЙ.
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  :}
procedure inkLLs_Invert(var SLL:pointer);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_Invert'}{$endIF}
var tmp:pointer;
    tmq:pointer;
{$deFine _m_protoInkLLs_69__tmp_POINTER_01:=tmp}
{$deFine _m_protoInkLLs_69__tmp_POINTER_02:=tmq}
{$deFine _M_protoInkLLs_69__var_FIRST     :=SLL}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_69__Invert.inc}
end;

//------------------------------------------------------------------------------

{:::[05v1] ПОСЛЕДНИЙ элемент списка (путем прямого перебора)
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @returns(ссылко-указатель на ПОСЛЕДНИЙ узел списка)
  :}
function inkLLs_getLast(const SLL:pointer):pointer;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_getLast'}{$endIF}
{$deFine _M_protoInkLLs_05v1__cst_FIRST  :=SLL}
{$deFine _M_protoInkLLs_05v1__out_LAST   :=result}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_05v1__getLast.inc}
end;

{:::[05v2][простой связный Список][Singly Linked Lists]
  ПОСЛЕДНИЙ элемент списка (путем прямого перебора), и общее кол-во элементов
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(Count вернется количество узлов списка)
  @returns(ссылко-указатель на ПОСЛЕДНИЙ узел списка)
  :}
function inkLLs_getLast(const SLL:pointer; out Count:tInkLLNodeCount):pointer;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_getLast count'}{$endIF}
var tmp:pointer;
{$deFine _M_protoInkLLs_05v2__tmp_POINTER:=tmp}
{$deFine _M_protoInkLLs_05v2__cst_FIRST  :=SLL}
{$deFine _M_protoInkLLs_05v2__out_COUNT  :=Count}
{$deFine _M_protoInkLLs_05v2__out_LAST   :=result}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_05v2__getLast.inc}
end;

{:::[05v2][простой связный Список][Singly Linked Lists]
  ПОСЛЕДНИЙ элемент списка (путем прямого перебора), и общее кол-во элементов
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(Count вернется количество узлов списка)
  @returns(ссылко-указатель на ПОСЛЕДНИЙ узел списка)
  :}
function inkLLs_getLast(const SLL:pointer; out Last:pointer):tInkLLNodeCount;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_getLast count'}{$endIF}
var tmp:pointer;
{$deFine _M_protoInkLLs_05v2__tmp_POINTER:=tmp}
{$deFine _M_protoInkLLs_05v2__cst_FIRST  :=SLL}
{$deFine _M_protoInkLLs_05v2__out_COUNT  :=result}
{$deFine _M_protoInkLLs_05v2__out_LAST   :=Last}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_05v2__getLast.inc}
end;

//------------------------------------------------------------------------------

{:::[C0v1] вырезать УЗЕЛ
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(Node ВЫРЕЗАЕМЫЙ элемент списка)
  :}
procedure inkLLs_cutNode(var SLL:pointer; const Node:pointer);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_cutNode'}{$endIF}
var tmp:pointer;
{$deFine _M_protoInkLLs_C0v1__tmp_POINTER:=tmp}
{$deFine _M_protoInkLLs_C0v1__var_FIRST  :=SLL}
{$deFine _M_protoInkLLs_C0v1__cst_NODE   :=Node}
begin
{$I protoInkLLs_bodyFNC_C0v1__cutNode.inc}
end;

{:::[C0v2] вырезать УЗЕЛ
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(Node ВЫРЕЗАЕМЫЙ элемент списка)
  @returns(@true -- элемент найден и вырезан; @false -- элемент НЕ найден => НЕвырезался)
  :}
function  inkLLs_cutNodeRES(var SLL:pointer; const Node:pointer):boolean;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_cutNodeRES'}{$endIF}
{$deFine _M_protoInkLLs_C0v2__var_FIRST:=SLL}
{$deFine _M_protoInkLLs_C0v2__cst_NODE :=Node}
{$deFine _M_protoInkLLs_C0v2__out_RES  :=result}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_C0v2__cutNode.inc}
end;

//------------------------------------------------------------------------------

{:::[С1] вырезать УЗЕЛ из Начала списка
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @returns(вырезанный Первый УЗЕЛ)
  ---
  # result^.next=?=@nil (тоесть скорее всего НЕ NIL)
  :}
function inkLLs_cutNodeFirst(var SLL:pointer):pointer;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_cutNodeFirst'}{$endIF}
{$deFine _M_protoInkLLs_C1__var_FIRST:=SLL}
{$deFine _M_protoInkLLs_C1__out_NODE :=result}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_C1__cutNodeFirst.inc}
end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

{:::[06] ВСТАВИТЬ элемент ПЕРВЫМ в списке
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(Node вставляемый УЗЕЛ)
  ---
  # проверки Node^.next==@nil НЕТ (точнее тока в DEBUG режиме)
  :}
procedure inkLLs_insNodeFirst(var SLL:pointer; const Node:pointer);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_insNodeFirst'}{$endIF}
{$deFine _M_protoInkLLs_06__var_FIRST:=SLL}
{$deFine _M_protoInkLLs_06__cst_NODE :=Node}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_06__insFirst.inc}
end;

{:::[07] ВСТАВИТЬ список СНАЧАЛА
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(List переменная-ссылко-указатель на первый узел вставляемого СПИСКА)
  :}
procedure inkLLs_insListFirst(var SLL:pointer; const List:pointer);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_insListFirst'}{$endIF}
{$deFine _M_protoInkLLs_07__var_FIRST:=SLL}
{$deFine _M_protoInkLLs_07__cst_LIST :=List}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_07__insFirst.inc}
end;

//------------------------------------------------------------------------------

{:::[CFv1] вырезать УЗЕЛ из КОНЦА списка
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @returns(вырезанный ПОСЛЕДНИЙ УЗЕЛ)
  ---
  # случай SLL==@NIL НЕ проверяется
  :}
function inkLLs_cutNodeLast(var SLL:pointer):pointer;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_cutNodeLast'}{$endIF}
{$deFine _M_protoInkLLs_CFv1__var_FIRST:=SLL}
{$deFine _M_protoInkLLs_CFv1__out_LAST :=result}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_CFv1__cutNodeLast.inc}
end;


{:::[CFv2] вырезать УЗЕЛ из КОНЦА списка
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @returns(вырезанный ПОСЛЕДНИЙ УЗЕЛ)
  ---
  # случай SLL==@NIL НЕ проверяется
  :}
function inkLLs_cutNodeLast(var SLL:pointer; out Count:tInkLLNodeCount):pointer;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkSLL_cutNodeLast count'}{$endIF}
{$deFine _M_protoInkLLs_CFv2__var_FIRST:=SLL}
{$deFine _M_protoInkLLs_CFv2__out_COUNT:=Count}
{$deFine _M_protoInkLLs_CFv2__out_LAST :=result}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_CFv2__cutNodeLast_count.inc}
end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

{:::[08v1] ВСТАВИТЬ элемент ПОСЛЕДНИМ в списке
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(Node вставляемый УЗЕЛ)
  ---
  # проверки Node^.next==@nil НЕТ (точнее тока в DEBUG режиме)
  :}
procedure inkLLs_insNodeLast(var SLL:pointer; const Node:pointer);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_insNodeLast'}{$endIF}
{$deFine _M_protoInkLLs_08v1__var_FIRST:=SLL}
{$deFine _M_protoInkLLs_08v1__cst_NODE :=Node}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_08v1__insLast.inc}
end;

{:::[08v2] ВСТАВИТЬ элемент ПОСЛЕДНИМ в списке
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(Count вернется количество узлов списка)
  @param(Node вставляемый УЗЕЛ)
  ---
  # проверки Node^.next==@nil НЕТ (точнее тока в DEBUG режиме)
  :}
procedure inkLLs_insNodeLast(var SLL:pointer; const Node:pointer; out Count:tInkLLNodeCount);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_insNodeLast count'}{$endIF}
{$deFine _M_protoInkLLs_08v2__var_FIRST:=SLL}
{$deFine _M_protoInkLLs_08v2__out_COUNT:=Count}
{$deFine _M_protoInkLLs_08v2__cst_NODE :=Node}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_08v2__insLast.inc}
end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

{:::[09v1] ВСТАВИТЬ ПОДсписок ПОСЛЕДНИМ в списке
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(Node вставляемый УЗЕЛ)
  ---
  # проверки Node^.next==@nil НЕТ (точнее тока в DEBUG режиме)
  :}
procedure inkLLs_insListLast(var SLL:pointer; const List:pointer);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_insListLast'}{$endIF}
{$deFine _M_protoInkLLs_09v1__var_FIRST:=SLL}
{$deFine _M_protoInkLLs_09v1__cst_LIST :=List}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_09v1__insLast.inc}
end;

{:::[09v2] ВСТАВИТЬ ПОДсписок ПОСЛЕДНИМ в списке
  @param(SLL переменная-ссылко-указатель на первый узел списка)
  @param(Count вернется количество узлов списка)
  @param(Node вставляемый УЗЕЛ)
  ---
  # проверки Node^.next==@nil НЕТ (точнее тока в DEBUG режиме)
  :}
procedure inkLLs_insListLast(var SLL:pointer; const List:pointer; out Count:tInkLLNodeCount);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_insNodeLast'}{$endIF}
{$deFine _M_protoInkLLs_09v2__var_FIRST:=SLL}
{$deFine _M_protoInkLLs_09v2__cst_LIST :=List}
{$deFine _M_protoInkLLs_09v2__out_COUNT:=Count}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_09v2__insLast.inc}
end;

//------------------------------------------------------------------------------

{:::[A1v1] элемент с Индексом
    @param(SLL переменная-ссылко-указатель на первый узел списка)
    @param(Index вернется количество узлов списка)
    @returns(ссылко-указатель на узел списка)
 :::}
function inkLLs_getNode(const SLL:pointer; index:tInkLLNodeIndex):pointer;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_getNode'}{$endIF}
{$deFine _M_protoInkLLs_A1v1__cst_FIRST:=SLL}
{$deFine _M_protoInkLLs_A1v1__var_Index:=index}
{$deFine _M_protoInkLLs_A1v1__out_NODE :=result}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_A1v1__getNode.inc}
end;

{:::[A1v2] элемент с Индексом или последний
    @param(SLL переменная-ссылко-указатель на первый узел списка)
    @param(Index вернется количество узлов списка)
    @returns(ссылко-указатель на узел списка)
 :::}
function inkLLs_getNodeOrLast(const SLL:pointer; Index:tInkLLNodeIndex):pointer;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkSLL_getNode_orLast'}{$endIF}
{$deFine _M_protoInkLLs_A1v2__cst_FIRST:=SLL}
{$deFine _M_protoInkLLs_A1v2__var_Index:=index}
{$deFine _M_protoInkLLs_A1v2__out_NODE :=result}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_A1v2__getNodeOrLast.inc}

//------------------------------------------------------------------------------

{:::[A2] элемент с Индексом
    @param(SLL переменная-ссылко-указатель на первый узел списка)
    @param(Node искомый элемент)
    @returns(индекс Элемента; ели нет то 0-1)
 :::}
function inkLLs_getIndex(const SLL:pointer; const Node:pointer; out Index:tInkLLNodeIndex):boolean;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_getIndex'}{$endIF}
{$deFine _M_protoInkLLs_A2__cst_FIRST :=SLL}
{$deFine _M_protoInkLLs_A2__cst_NODE  :=Node}
{$deFine _M_protoInkLLs_A2__out_INDEX :=index}
{$deFine _M_protoInkLLs_A2__out_RESULT:=result}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_A2__getIndex.inc}
end;

//------------------------------------------------------------------------------

{:::[A3] ВСТАВИТЬ элементом c ИНДЕКСОМ
    @param(SLL переменная-ссылко-указатель на первый узел списка)
    @param(Node искомый элемент)
    @returns(индекс Элемента; ели нет то 0-1)
 :::}
procedure inkLLs_insNodeIndex(var SLL:pointer; const Node:pointer; Index:tInkLLNodeIndex);
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_insNodeIndex'}{$endIF}
{$deFine _M_protoInkLLs_A3__var_FIRST:=SLL}
{$deFine _M_protoInkLLs_A3__cst_NODE :=Node}
{$deFine _M_protoInkLLs_A3__var_INDEX:=index}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_A3__insNodeIndex.inc}
end;

//------------------------------------------------------------------------------

{:::[A5v1] ВЫРЕЗАТЬ элемент c ИНДЕКСОМ
    @param(SLL переменная-ссылко-указатель на первый узел списка)
    @param(Index индекс ВЫРЕЗАЕМОГО элемента)
    @returns()
    ---
    # в результате выполнения result^.Next<>nil
 :::}
function inkLLs_cutNodeIndex(var SLL:pointer; Index:tInkLLNodeIndex):pointer;
{$ifDef inkLLsimple_fncHeadMessage}{$message 'inkLLs_insNodeIndex'}{$endIF}
{$deFine _M_protoInkLLs_A5v1__var_FIRST:=SLL}
{$deFine _M_protoInkLLs_A5v1__var_INDEX:=index}
{$deFine _M_protoInkLLs_A5v1__out_NODE :=result}
begin //< для удобства навигации
{$I protoInkLLs_bodyFNC_A5v1__insNodeIndex.inc}
end;

end.

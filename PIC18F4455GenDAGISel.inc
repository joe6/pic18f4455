//===- TableGen'erated file -------------------------------------*- C++ -*-===//
//
// DAG Instruction Selector for the PIC18F4455 target
//
// Automatically generated file, do not edit!
//
//===----------------------------------------------------------------------===//

// *** NOTE: This file is #included into the middle of the target
// *** instruction selector class.  These functions are really methods.

// The main instruction selector code.
SDNode *SelectCode(SDNode *N) {
  // Opcodes are emitted as 2 bytes, TARGET_OPCODE handles this.
  #define TARGET_OPCODE(X) X & 255, unsigned(X) >> 8
  static const unsigned char MatcherTable[] = {
/*0*/     OPC_SwitchOpcode /*27 cases */, 64|128,9/*1216*/,  TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Store),// ->1221
/*5*/       OPC_RecordNode,   // #0 = 'PIC18F4455Store' chained node
/*6*/       OPC_Scope, 60|128,8/*1084*/, /*->1093*/ // 2 children in Scope
/*9*/         OPC_MoveChild, 1,
/*11*/        OPC_SwitchOpcode /*10 cases */, 0|128,1/*128*/,  TARGET_OPCODE(ISD::OR),// ->144
/*16*/          OPC_Scope, 62, /*->80*/ // 2 children in Scope
/*18*/            OPC_RecordChild0, // #1 = $src
/*19*/            OPC_MoveChild, 1,
/*21*/            OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*24*/            OPC_RecordNode, // #2 = 'PIC18F4455Load' chained node
/*25*/            OPC_CheckFoldableChainNode,
/*26*/            OPC_RecordChild1, // #3 = $ptrlo
/*27*/            OPC_RecordChild2, // #4 = $ptrhi
/*28*/            OPC_MoveChild, 2,
/*30*/            OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*33*/            OPC_MoveParent,
/*34*/            OPC_RecordChild3, // #5 = $offset
/*35*/            OPC_MoveChild, 3,
/*37*/            OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*40*/            OPC_MoveParent,
/*41*/            OPC_MoveParent,
/*42*/            OPC_MoveParent,
/*43*/            OPC_MoveChild, 2,
/*45*/            OPC_CheckSame, 3,
/*47*/            OPC_MoveParent,
/*48*/            OPC_MoveChild, 3,
/*50*/            OPC_CheckSame, 4,
/*52*/            OPC_MoveParent,
/*53*/            OPC_MoveChild, 4,
/*55*/            OPC_CheckSame, 5,
/*57*/            OPC_MoveParent,
/*58*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectDirectAddr:$ptrlo #6
/*61*/            OPC_EmitMergeInputChains, 2, 0, 2, 
/*65*/            OPC_EmitConvertToTarget, 5,
/*67*/            OPC_EmitConvertToTarget, 4,
/*69*/            OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::OrWF), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i8, 4/*#Ops*/, 1, 7, 6, 8, 
                  // Src: (PIC18F4455Store (or:i8 GR8:i8:$src, (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset)), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                  // Dst: (OrWF:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*80*/          /*Scope*/ 62, /*->143*/
/*81*/            OPC_MoveChild, 0,
/*83*/            OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*86*/            OPC_RecordNode, // #1 = 'PIC18F4455Load' chained node
/*87*/            OPC_CheckFoldableChainNode,
/*88*/            OPC_RecordChild1, // #2 = $ptrlo
/*89*/            OPC_RecordChild2, // #3 = $ptrhi
/*90*/            OPC_MoveChild, 2,
/*92*/            OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*95*/            OPC_MoveParent,
/*96*/            OPC_RecordChild3, // #4 = $offset
/*97*/            OPC_MoveChild, 3,
/*99*/            OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*102*/           OPC_MoveParent,
/*103*/           OPC_MoveParent,
/*104*/           OPC_RecordChild1, // #5 = $src
/*105*/           OPC_MoveParent,
/*106*/           OPC_MoveChild, 2,
/*108*/           OPC_CheckSame, 2,
/*110*/           OPC_MoveParent,
/*111*/           OPC_MoveChild, 3,
/*113*/           OPC_CheckSame, 3,
/*115*/           OPC_MoveParent,
/*116*/           OPC_MoveChild, 4,
/*118*/           OPC_CheckSame, 4,
/*120*/           OPC_MoveParent,
/*121*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectDirectAddr:$ptrlo #6
/*124*/           OPC_EmitMergeInputChains, 2, 0, 1, 
/*128*/           OPC_EmitConvertToTarget, 4,
/*130*/           OPC_EmitConvertToTarget, 3,
/*132*/           OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::OrWF), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i8, 4/*#Ops*/, 5, 7, 6, 8, 
                  // Src: (PIC18F4455Store (or:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                  // Dst: (OrWF:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*143*/         0, /*End of Scope*/
              /*SwitchOpcode*/ 0|128,1/*128*/,  TARGET_OPCODE(ISD::XOR),// ->276
/*148*/         OPC_Scope, 62, /*->212*/ // 2 children in Scope
/*150*/           OPC_RecordChild0, // #1 = $src
/*151*/           OPC_MoveChild, 1,
/*153*/           OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*156*/           OPC_RecordNode, // #2 = 'PIC18F4455Load' chained node
/*157*/           OPC_CheckFoldableChainNode,
/*158*/           OPC_RecordChild1, // #3 = $ptrlo
/*159*/           OPC_RecordChild2, // #4 = $ptrhi
/*160*/           OPC_MoveChild, 2,
/*162*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*165*/           OPC_MoveParent,
/*166*/           OPC_RecordChild3, // #5 = $offset
/*167*/           OPC_MoveChild, 3,
/*169*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*172*/           OPC_MoveParent,
/*173*/           OPC_MoveParent,
/*174*/           OPC_MoveParent,
/*175*/           OPC_MoveChild, 2,
/*177*/           OPC_CheckSame, 3,
/*179*/           OPC_MoveParent,
/*180*/           OPC_MoveChild, 3,
/*182*/           OPC_CheckSame, 4,
/*184*/           OPC_MoveParent,
/*185*/           OPC_MoveChild, 4,
/*187*/           OPC_CheckSame, 5,
/*189*/           OPC_MoveParent,
/*190*/           OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectDirectAddr:$ptrlo #6
/*193*/           OPC_EmitMergeInputChains, 2, 0, 2, 
/*197*/           OPC_EmitConvertToTarget, 5,
/*199*/           OPC_EmitConvertToTarget, 4,
/*201*/           OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::XOrWF), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i8, 4/*#Ops*/, 1, 7, 6, 8, 
                  // Src: (PIC18F4455Store (xor:i8 GR8:i8:$src, (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset)), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                  // Dst: (XOrWF:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*212*/         /*Scope*/ 62, /*->275*/
/*213*/           OPC_MoveChild, 0,
/*215*/           OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*218*/           OPC_RecordNode, // #1 = 'PIC18F4455Load' chained node
/*219*/           OPC_CheckFoldableChainNode,
/*220*/           OPC_RecordChild1, // #2 = $ptrlo
/*221*/           OPC_RecordChild2, // #3 = $ptrhi
/*222*/           OPC_MoveChild, 2,
/*224*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*227*/           OPC_MoveParent,
/*228*/           OPC_RecordChild3, // #4 = $offset
/*229*/           OPC_MoveChild, 3,
/*231*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*234*/           OPC_MoveParent,
/*235*/           OPC_MoveParent,
/*236*/           OPC_RecordChild1, // #5 = $src
/*237*/           OPC_MoveParent,
/*238*/           OPC_MoveChild, 2,
/*240*/           OPC_CheckSame, 2,
/*242*/           OPC_MoveParent,
/*243*/           OPC_MoveChild, 3,
/*245*/           OPC_CheckSame, 3,
/*247*/           OPC_MoveParent,
/*248*/           OPC_MoveChild, 4,
/*250*/           OPC_CheckSame, 4,
/*252*/           OPC_MoveParent,
/*253*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectDirectAddr:$ptrlo #6
/*256*/           OPC_EmitMergeInputChains, 2, 0, 1, 
/*260*/           OPC_EmitConvertToTarget, 4,
/*262*/           OPC_EmitConvertToTarget, 3,
/*264*/           OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::XOrWF), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i8, 4/*#Ops*/, 5, 7, 6, 8, 
                  // Src: (PIC18F4455Store (xor:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                  // Dst: (XOrWF:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*275*/         0, /*End of Scope*/
              /*SwitchOpcode*/ 0|128,1/*128*/,  TARGET_OPCODE(ISD::AND),// ->408
/*280*/         OPC_Scope, 62, /*->344*/ // 2 children in Scope
/*282*/           OPC_RecordChild0, // #1 = $src
/*283*/           OPC_MoveChild, 1,
/*285*/           OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*288*/           OPC_RecordNode, // #2 = 'PIC18F4455Load' chained node
/*289*/           OPC_CheckFoldableChainNode,
/*290*/           OPC_RecordChild1, // #3 = $ptrlo
/*291*/           OPC_RecordChild2, // #4 = $ptrhi
/*292*/           OPC_MoveChild, 2,
/*294*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*297*/           OPC_MoveParent,
/*298*/           OPC_RecordChild3, // #5 = $offset
/*299*/           OPC_MoveChild, 3,
/*301*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*304*/           OPC_MoveParent,
/*305*/           OPC_MoveParent,
/*306*/           OPC_MoveParent,
/*307*/           OPC_MoveChild, 2,
/*309*/           OPC_CheckSame, 3,
/*311*/           OPC_MoveParent,
/*312*/           OPC_MoveChild, 3,
/*314*/           OPC_CheckSame, 4,
/*316*/           OPC_MoveParent,
/*317*/           OPC_MoveChild, 4,
/*319*/           OPC_CheckSame, 5,
/*321*/           OPC_MoveParent,
/*322*/           OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectDirectAddr:$ptrlo #6
/*325*/           OPC_EmitMergeInputChains, 2, 0, 2, 
/*329*/           OPC_EmitConvertToTarget, 5,
/*331*/           OPC_EmitConvertToTarget, 4,
/*333*/           OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::AndWF), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i8, 4/*#Ops*/, 1, 7, 6, 8, 
                  // Src: (PIC18F4455Store (and:i8 GR8:i8:$src, (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset)), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                  // Dst: (AndWF:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*344*/         /*Scope*/ 62, /*->407*/
/*345*/           OPC_MoveChild, 0,
/*347*/           OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*350*/           OPC_RecordNode, // #1 = 'PIC18F4455Load' chained node
/*351*/           OPC_CheckFoldableChainNode,
/*352*/           OPC_RecordChild1, // #2 = $ptrlo
/*353*/           OPC_RecordChild2, // #3 = $ptrhi
/*354*/           OPC_MoveChild, 2,
/*356*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*359*/           OPC_MoveParent,
/*360*/           OPC_RecordChild3, // #4 = $offset
/*361*/           OPC_MoveChild, 3,
/*363*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*366*/           OPC_MoveParent,
/*367*/           OPC_MoveParent,
/*368*/           OPC_RecordChild1, // #5 = $src
/*369*/           OPC_MoveParent,
/*370*/           OPC_MoveChild, 2,
/*372*/           OPC_CheckSame, 2,
/*374*/           OPC_MoveParent,
/*375*/           OPC_MoveChild, 3,
/*377*/           OPC_CheckSame, 3,
/*379*/           OPC_MoveParent,
/*380*/           OPC_MoveChild, 4,
/*382*/           OPC_CheckSame, 4,
/*384*/           OPC_MoveParent,
/*385*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectDirectAddr:$ptrlo #6
/*388*/           OPC_EmitMergeInputChains, 2, 0, 1, 
/*392*/           OPC_EmitConvertToTarget, 4,
/*394*/           OPC_EmitConvertToTarget, 3,
/*396*/           OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::AndWF), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i8, 4/*#Ops*/, 5, 7, 6, 8, 
                  // Src: (PIC18F4455Store (and:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                  // Dst: (AndWF:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*407*/         0, /*End of Scope*/
              /*SwitchOpcode*/ 0|128,1/*128*/,  TARGET_OPCODE(ISD::ADD),// ->540
/*412*/         OPC_Scope, 62, /*->476*/ // 2 children in Scope
/*414*/           OPC_RecordChild0, // #1 = $src
/*415*/           OPC_MoveChild, 1,
/*417*/           OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*420*/           OPC_RecordNode, // #2 = 'PIC18F4455Load' chained node
/*421*/           OPC_CheckFoldableChainNode,
/*422*/           OPC_RecordChild1, // #3 = $ptrlo
/*423*/           OPC_RecordChild2, // #4 = $ptrhi
/*424*/           OPC_MoveChild, 2,
/*426*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*429*/           OPC_MoveParent,
/*430*/           OPC_RecordChild3, // #5 = $offset
/*431*/           OPC_MoveChild, 3,
/*433*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*436*/           OPC_MoveParent,
/*437*/           OPC_MoveParent,
/*438*/           OPC_MoveParent,
/*439*/           OPC_MoveChild, 2,
/*441*/           OPC_CheckSame, 3,
/*443*/           OPC_MoveParent,
/*444*/           OPC_MoveChild, 3,
/*446*/           OPC_CheckSame, 4,
/*448*/           OPC_MoveParent,
/*449*/           OPC_MoveChild, 4,
/*451*/           OPC_CheckSame, 5,
/*453*/           OPC_MoveParent,
/*454*/           OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectDirectAddr:$ptrlo #6
/*457*/           OPC_EmitMergeInputChains, 2, 0, 2, 
/*461*/           OPC_EmitConvertToTarget, 5,
/*463*/           OPC_EmitConvertToTarget, 4,
/*465*/           OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addwf_1), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i8, 4/*#Ops*/, 1, 7, 6, 8, 
                  // Src: (PIC18F4455Store (add:i8 GR8:i8:$src, (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset)), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                  // Dst: (addwf_1:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*476*/         /*Scope*/ 62, /*->539*/
/*477*/           OPC_MoveChild, 0,
/*479*/           OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*482*/           OPC_RecordNode, // #1 = 'PIC18F4455Load' chained node
/*483*/           OPC_CheckFoldableChainNode,
/*484*/           OPC_RecordChild1, // #2 = $ptrlo
/*485*/           OPC_RecordChild2, // #3 = $ptrhi
/*486*/           OPC_MoveChild, 2,
/*488*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*491*/           OPC_MoveParent,
/*492*/           OPC_RecordChild3, // #4 = $offset
/*493*/           OPC_MoveChild, 3,
/*495*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*498*/           OPC_MoveParent,
/*499*/           OPC_MoveParent,
/*500*/           OPC_RecordChild1, // #5 = $src
/*501*/           OPC_MoveParent,
/*502*/           OPC_MoveChild, 2,
/*504*/           OPC_CheckSame, 2,
/*506*/           OPC_MoveParent,
/*507*/           OPC_MoveChild, 3,
/*509*/           OPC_CheckSame, 3,
/*511*/           OPC_MoveParent,
/*512*/           OPC_MoveChild, 4,
/*514*/           OPC_CheckSame, 4,
/*516*/           OPC_MoveParent,
/*517*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectDirectAddr:$ptrlo #6
/*520*/           OPC_EmitMergeInputChains, 2, 0, 1, 
/*524*/           OPC_EmitConvertToTarget, 4,
/*526*/           OPC_EmitConvertToTarget, 3,
/*528*/           OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addwf_1), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i8, 4/*#Ops*/, 5, 7, 6, 8, 
                  // Src: (PIC18F4455Store (add:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                  // Dst: (addwf_1:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*539*/         0, /*End of Scope*/
              /*SwitchOpcode*/ 7|128,1/*135*/,  TARGET_OPCODE(ISD::ADDC),// ->679
/*544*/         OPC_RecordNode, // #1 = 'addc' flag output node
/*545*/         OPC_Scope, 65, /*->612*/ // 2 children in Scope
/*547*/           OPC_RecordChild0, // #2 = $src
/*548*/           OPC_MoveChild, 1,
/*550*/           OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*553*/           OPC_RecordNode, // #3 = 'PIC18F4455Load' chained node
/*554*/           OPC_CheckFoldableChainNode,
/*555*/           OPC_RecordChild1, // #4 = $ptrlo
/*556*/           OPC_RecordChild2, // #5 = $ptrhi
/*557*/           OPC_MoveChild, 2,
/*559*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*562*/           OPC_MoveParent,
/*563*/           OPC_RecordChild3, // #6 = $offset
/*564*/           OPC_MoveChild, 3,
/*566*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*569*/           OPC_MoveParent,
/*570*/           OPC_MoveParent,
/*571*/           OPC_MoveParent,
/*572*/           OPC_MoveChild, 2,
/*574*/           OPC_CheckSame, 4,
/*576*/           OPC_MoveParent,
/*577*/           OPC_MoveChild, 3,
/*579*/           OPC_CheckSame, 5,
/*581*/           OPC_MoveParent,
/*582*/           OPC_MoveChild, 4,
/*584*/           OPC_CheckSame, 6,
/*586*/           OPC_MoveParent,
/*587*/           OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectDirectAddr:$ptrlo #7
/*590*/           OPC_EmitMergeInputChains, 2, 0, 3, 
/*594*/           OPC_EmitConvertToTarget, 6,
/*596*/           OPC_EmitConvertToTarget, 5,
/*598*/           OPC_MarkFlagResults, 1, 1, 
/*601*/           OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addwf_2), 0|OPFL_Chain|OPFL_FlagOutput,
                      1/*#VTs*/, MVT::i8, 4/*#Ops*/, 2, 8, 7, 9, 
                  // Src: (PIC18F4455Store (addc:i8 GR8:i8:$src, (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset)), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                  // Dst: (addwf_2:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*612*/         /*Scope*/ 65, /*->678*/
/*613*/           OPC_MoveChild, 0,
/*615*/           OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*618*/           OPC_RecordNode, // #2 = 'PIC18F4455Load' chained node
/*619*/           OPC_CheckFoldableChainNode,
/*620*/           OPC_RecordChild1, // #3 = $ptrlo
/*621*/           OPC_RecordChild2, // #4 = $ptrhi
/*622*/           OPC_MoveChild, 2,
/*624*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*627*/           OPC_MoveParent,
/*628*/           OPC_RecordChild3, // #5 = $offset
/*629*/           OPC_MoveChild, 3,
/*631*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*634*/           OPC_MoveParent,
/*635*/           OPC_MoveParent,
/*636*/           OPC_RecordChild1, // #6 = $src
/*637*/           OPC_MoveParent,
/*638*/           OPC_MoveChild, 2,
/*640*/           OPC_CheckSame, 3,
/*642*/           OPC_MoveParent,
/*643*/           OPC_MoveChild, 3,
/*645*/           OPC_CheckSame, 4,
/*647*/           OPC_MoveParent,
/*648*/           OPC_MoveChild, 4,
/*650*/           OPC_CheckSame, 5,
/*652*/           OPC_MoveParent,
/*653*/           OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectDirectAddr:$ptrlo #7
/*656*/           OPC_EmitMergeInputChains, 2, 0, 2, 
/*660*/           OPC_EmitConvertToTarget, 5,
/*662*/           OPC_EmitConvertToTarget, 4,
/*664*/           OPC_MarkFlagResults, 1, 1, 
/*667*/           OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addwf_2), 0|OPFL_Chain|OPFL_FlagOutput,
                      1/*#VTs*/, MVT::i8, 4/*#Ops*/, 6, 8, 7, 9, 
                  // Src: (PIC18F4455Store (addc:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                  // Dst: (addwf_2:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*678*/         0, /*End of Scope*/
              /*SwitchOpcode*/ 8|128,1/*136*/,  TARGET_OPCODE(ISD::ADDE),// ->819
/*683*/         OPC_RecordNode, // #1 = 'adde' flag output node
/*684*/         OPC_CaptureFlagInput,
/*685*/         OPC_Scope, 65, /*->752*/ // 2 children in Scope
/*687*/           OPC_RecordChild0, // #2 = $src
/*688*/           OPC_MoveChild, 1,
/*690*/           OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*693*/           OPC_RecordNode, // #3 = 'PIC18F4455Load' chained node
/*694*/           OPC_CheckFoldableChainNode,
/*695*/           OPC_RecordChild1, // #4 = $ptrlo
/*696*/           OPC_RecordChild2, // #5 = $ptrhi
/*697*/           OPC_MoveChild, 2,
/*699*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*702*/           OPC_MoveParent,
/*703*/           OPC_RecordChild3, // #6 = $offset
/*704*/           OPC_MoveChild, 3,
/*706*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*709*/           OPC_MoveParent,
/*710*/           OPC_MoveParent,
/*711*/           OPC_MoveParent,
/*712*/           OPC_MoveChild, 2,
/*714*/           OPC_CheckSame, 4,
/*716*/           OPC_MoveParent,
/*717*/           OPC_MoveChild, 3,
/*719*/           OPC_CheckSame, 5,
/*721*/           OPC_MoveParent,
/*722*/           OPC_MoveChild, 4,
/*724*/           OPC_CheckSame, 6,
/*726*/           OPC_MoveParent,
/*727*/           OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectDirectAddr:$ptrlo #7
/*730*/           OPC_EmitMergeInputChains, 2, 0, 3, 
/*734*/           OPC_EmitConvertToTarget, 6,
/*736*/           OPC_EmitConvertToTarget, 5,
/*738*/           OPC_MarkFlagResults, 1, 1, 
/*741*/           OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addwfc), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput,
                      1/*#VTs*/, MVT::i8, 4/*#Ops*/, 2, 8, 7, 9, 
                  // Src: (PIC18F4455Store (adde:i8 GR8:i8:$src, (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset)), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                  // Dst: (addwfc:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*752*/         /*Scope*/ 65, /*->818*/
/*753*/           OPC_MoveChild, 0,
/*755*/           OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*758*/           OPC_RecordNode, // #2 = 'PIC18F4455Load' chained node
/*759*/           OPC_CheckFoldableChainNode,
/*760*/           OPC_RecordChild1, // #3 = $ptrlo
/*761*/           OPC_RecordChild2, // #4 = $ptrhi
/*762*/           OPC_MoveChild, 2,
/*764*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*767*/           OPC_MoveParent,
/*768*/           OPC_RecordChild3, // #5 = $offset
/*769*/           OPC_MoveChild, 3,
/*771*/           OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*774*/           OPC_MoveParent,
/*775*/           OPC_MoveParent,
/*776*/           OPC_RecordChild1, // #6 = $src
/*777*/           OPC_MoveParent,
/*778*/           OPC_MoveChild, 2,
/*780*/           OPC_CheckSame, 3,
/*782*/           OPC_MoveParent,
/*783*/           OPC_MoveChild, 3,
/*785*/           OPC_CheckSame, 4,
/*787*/           OPC_MoveParent,
/*788*/           OPC_MoveChild, 4,
/*790*/           OPC_CheckSame, 5,
/*792*/           OPC_MoveParent,
/*793*/           OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectDirectAddr:$ptrlo #7
/*796*/           OPC_EmitMergeInputChains, 2, 0, 2, 
/*800*/           OPC_EmitConvertToTarget, 5,
/*802*/           OPC_EmitConvertToTarget, 4,
/*804*/           OPC_MarkFlagResults, 1, 1, 
/*807*/           OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addwfc), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput,
                      1/*#VTs*/, MVT::i8, 4/*#Ops*/, 6, 8, 7, 9, 
                  // Src: (PIC18F4455Store (adde:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                  // Dst: (addwfc:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*818*/         0, /*End of Scope*/
              /*SwitchOpcode*/ 62,  TARGET_OPCODE(ISD::SUB),// ->884
/*822*/         OPC_MoveChild, 0,
/*824*/         OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*827*/         OPC_RecordNode, // #1 = 'PIC18F4455Load' chained node
/*828*/         OPC_CheckFoldableChainNode,
/*829*/         OPC_RecordChild1, // #2 = $ptrlo
/*830*/         OPC_RecordChild2, // #3 = $ptrhi
/*831*/         OPC_MoveChild, 2,
/*833*/         OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*836*/         OPC_MoveParent,
/*837*/         OPC_RecordChild3, // #4 = $offset
/*838*/         OPC_MoveChild, 3,
/*840*/         OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*843*/         OPC_MoveParent,
/*844*/         OPC_MoveParent,
/*845*/         OPC_RecordChild1, // #5 = $src
/*846*/         OPC_MoveParent,
/*847*/         OPC_MoveChild, 2,
/*849*/         OPC_CheckSame, 2,
/*851*/         OPC_MoveParent,
/*852*/         OPC_MoveChild, 3,
/*854*/         OPC_CheckSame, 3,
/*856*/         OPC_MoveParent,
/*857*/         OPC_MoveChild, 4,
/*859*/         OPC_CheckSame, 4,
/*861*/         OPC_MoveParent,
/*862*/         OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectDirectAddr:$ptrlo #6
/*865*/         OPC_EmitMergeInputChains, 2, 0, 1, 
/*869*/         OPC_EmitConvertToTarget, 4,
/*871*/         OPC_EmitConvertToTarget, 3,
/*873*/         OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::subwf_1), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i8, 4/*#Ops*/, 5, 7, 6, 8, 
                // Src: (PIC18F4455Store (sub:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                // Dst: (subwf_1:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
              /*SwitchOpcode*/ 66,  TARGET_OPCODE(ISD::SUBC),// ->953
/*887*/         OPC_RecordNode, // #1 = 'subc' flag output node
/*888*/         OPC_MoveChild, 0,
/*890*/         OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*893*/         OPC_RecordNode, // #2 = 'PIC18F4455Load' chained node
/*894*/         OPC_CheckFoldableChainNode,
/*895*/         OPC_RecordChild1, // #3 = $ptrlo
/*896*/         OPC_RecordChild2, // #4 = $ptrhi
/*897*/         OPC_MoveChild, 2,
/*899*/         OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*902*/         OPC_MoveParent,
/*903*/         OPC_RecordChild3, // #5 = $offset
/*904*/         OPC_MoveChild, 3,
/*906*/         OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*909*/         OPC_MoveParent,
/*910*/         OPC_MoveParent,
/*911*/         OPC_RecordChild1, // #6 = $src
/*912*/         OPC_MoveParent,
/*913*/         OPC_MoveChild, 2,
/*915*/         OPC_CheckSame, 3,
/*917*/         OPC_MoveParent,
/*918*/         OPC_MoveChild, 3,
/*920*/         OPC_CheckSame, 4,
/*922*/         OPC_MoveParent,
/*923*/         OPC_MoveChild, 4,
/*925*/         OPC_CheckSame, 5,
/*927*/         OPC_MoveParent,
/*928*/         OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectDirectAddr:$ptrlo #7
/*931*/         OPC_EmitMergeInputChains, 2, 0, 2, 
/*935*/         OPC_EmitConvertToTarget, 5,
/*937*/         OPC_EmitConvertToTarget, 4,
/*939*/         OPC_MarkFlagResults, 1, 1, 
/*942*/         OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::subwf_2), 0|OPFL_Chain|OPFL_FlagOutput,
                    1/*#VTs*/, MVT::i8, 4/*#Ops*/, 6, 8, 7, 9, 
                // Src: (PIC18F4455Store (subc:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                // Dst: (subwf_2:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
              /*SwitchOpcode*/ 67,  TARGET_OPCODE(ISD::SUBE),// ->1023
/*956*/         OPC_RecordNode, // #1 = 'sube' flag output node
/*957*/         OPC_CaptureFlagInput,
/*958*/         OPC_MoveChild, 0,
/*960*/         OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*963*/         OPC_RecordNode, // #2 = 'PIC18F4455Load' chained node
/*964*/         OPC_CheckFoldableChainNode,
/*965*/         OPC_RecordChild1, // #3 = $ptrlo
/*966*/         OPC_RecordChild2, // #4 = $ptrhi
/*967*/         OPC_MoveChild, 2,
/*969*/         OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*972*/         OPC_MoveParent,
/*973*/         OPC_RecordChild3, // #5 = $offset
/*974*/         OPC_MoveChild, 3,
/*976*/         OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*979*/         OPC_MoveParent,
/*980*/         OPC_MoveParent,
/*981*/         OPC_RecordChild1, // #6 = $src
/*982*/         OPC_MoveParent,
/*983*/         OPC_MoveChild, 2,
/*985*/         OPC_CheckSame, 3,
/*987*/         OPC_MoveParent,
/*988*/         OPC_MoveChild, 3,
/*990*/         OPC_CheckSame, 4,
/*992*/         OPC_MoveParent,
/*993*/         OPC_MoveChild, 4,
/*995*/         OPC_CheckSame, 5,
/*997*/         OPC_MoveParent,
/*998*/         OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectDirectAddr:$ptrlo #7
/*1001*/        OPC_EmitMergeInputChains, 2, 0, 2, 
/*1005*/        OPC_EmitConvertToTarget, 5,
/*1007*/        OPC_EmitConvertToTarget, 4,
/*1009*/        OPC_MarkFlagResults, 1, 1, 
/*1012*/        OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::subwfb), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput,
                    1/*#VTs*/, MVT::i8, 4/*#Ops*/, 6, 8, 7, 9, 
                // Src: (PIC18F4455Store (sube:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                // Dst: (subwfb:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
              /*SwitchOpcode*/ 66,  TARGET_OPCODE(PIC18F4455ISD::SUBCC),// ->1092
/*1026*/        OPC_RecordNode, // #1 = 'PIC18F4455Subcc' flag output node
/*1027*/        OPC_MoveChild, 0,
/*1029*/        OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1032*/        OPC_RecordNode, // #2 = 'PIC18F4455Load' chained node
/*1033*/        OPC_CheckFoldableChainNode,
/*1034*/        OPC_RecordChild1, // #3 = $ptrlo
/*1035*/        OPC_RecordChild2, // #4 = $ptrhi
/*1036*/        OPC_MoveChild, 2,
/*1038*/        OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1041*/        OPC_MoveParent,
/*1042*/        OPC_RecordChild3, // #5 = $offset
/*1043*/        OPC_MoveChild, 3,
/*1045*/        OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1048*/        OPC_MoveParent,
/*1049*/        OPC_MoveParent,
/*1050*/        OPC_RecordChild1, // #6 = $src
/*1051*/        OPC_MoveParent,
/*1052*/        OPC_MoveChild, 2,
/*1054*/        OPC_CheckSame, 3,
/*1056*/        OPC_MoveParent,
/*1057*/        OPC_MoveChild, 3,
/*1059*/        OPC_CheckSame, 4,
/*1061*/        OPC_MoveParent,
/*1062*/        OPC_MoveChild, 4,
/*1064*/        OPC_CheckSame, 5,
/*1066*/        OPC_MoveParent,
/*1067*/        OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectDirectAddr:$ptrlo #7
/*1070*/        OPC_EmitMergeInputChains, 2, 0, 2, 
/*1074*/        OPC_EmitConvertToTarget, 5,
/*1076*/        OPC_EmitConvertToTarget, 4,
/*1078*/        OPC_MarkFlagResults, 1, 1, 
/*1081*/        OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::subwf_cc), 0|OPFL_Chain|OPFL_FlagOutput,
                    1/*#VTs*/, MVT::i8, 4/*#Ops*/, 6, 8, 7, 9, 
                // Src: (PIC18F4455Store (PIC18F4455Subcc:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src), diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 33
                // Dst: (subwf_cc:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
              0, // EndSwitchOpcode
/*1093*/    /*Scope*/ 126, /*->1220*/
/*1094*/      OPC_RecordChild1, // #1 = $val
/*1095*/      OPC_Scope, 71, /*->1168*/ // 2 children in Scope
/*1097*/        OPC_RecordChild2, // #2 = $ptrlo
/*1098*/        OPC_MoveChild, 2,
/*1100*/        OPC_SwitchOpcode /*2 cases */, 30,  TARGET_OPCODE(ISD::TargetGlobalAddress),// ->1134
/*1104*/          OPC_MoveParent,
/*1105*/          OPC_RecordChild3, // #3 = $ptrhi
/*1106*/          OPC_MoveChild, 3,
/*1108*/          OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1111*/          OPC_MoveParent,
/*1112*/          OPC_RecordChild4, // #4 = $offset
/*1113*/          OPC_MoveChild, 4,
/*1115*/          OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1118*/          OPC_MoveParent,
/*1119*/          OPC_EmitMergeInputChains1_0,
/*1120*/          OPC_EmitConvertToTarget, 4,
/*1122*/          OPC_EmitConvertToTarget, 3,
/*1124*/          OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::movwf), 0|OPFL_Chain,
                      0/*#VTs*/, 4/*#Ops*/, 1, 5, 2, 6, 
                  // Src: (PIC18F4455Store GR8:i8:$val, (tglobaladdr:i8):$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 12
                  // Dst: (movwf GR8:i8:$val, (imm:i8):$offset, (tglobaladdr:i8):$ptrlo, (imm:i8):$ptrhi)
                /*SwitchOpcode*/ 30,  TARGET_OPCODE(ISD::TargetExternalSymbol),// ->1167
/*1137*/          OPC_MoveParent,
/*1138*/          OPC_RecordChild3, // #3 = $ptrhi
/*1139*/          OPC_MoveChild, 3,
/*1141*/          OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1144*/          OPC_MoveParent,
/*1145*/          OPC_RecordChild4, // #4 = $offset
/*1146*/          OPC_MoveChild, 4,
/*1148*/          OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1151*/          OPC_MoveParent,
/*1152*/          OPC_EmitMergeInputChains1_0,
/*1153*/          OPC_EmitConvertToTarget, 4,
/*1155*/          OPC_EmitConvertToTarget, 3,
/*1157*/          OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::movwf_1), 0|OPFL_Chain,
                      0/*#VTs*/, 4/*#Ops*/, 1, 5, 2, 6, 
                  // Src: (PIC18F4455Store GR8:i8:$val, (texternalsym:i8):$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 12
                  // Dst: (movwf_1 GR8:i8:$val, (imm:i8):$offset, (texternalsym:i8):$ptrlo, (imm:i8):$ptrhi)
                0, // EndSwitchOpcode
/*1168*/      /*Scope*/ 50, /*->1219*/
/*1169*/        OPC_MoveChild, 2,
/*1171*/        OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::MTLO),
/*1174*/        OPC_RecordChild0, // #2 = $loaddr
/*1175*/        OPC_MoveParent,
/*1176*/        OPC_MoveChild, 3,
/*1178*/        OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::MTHI),
/*1181*/        OPC_RecordChild0, // #3 = $hiaddr
/*1182*/        OPC_MoveParent,
/*1183*/        OPC_RecordChild4, // #4 = $offset
/*1184*/        OPC_MoveChild, 4,
/*1186*/        OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1189*/        OPC_MoveParent,
/*1190*/        OPC_EmitMergeInputChains1_0,
/*1191*/        OPC_EmitNode, TARGET_OPCODE(PIC18F4455::set_fsrlo), 0,
                    1/*#VTs*/, MVT::i16, 1/*#Ops*/, 2,  // Results = #5 
/*1199*/        OPC_EmitNode, TARGET_OPCODE(PIC18F4455::set_fsrhi), 0,
                    1/*#VTs*/, MVT::i16, 2/*#Ops*/, 5, 3,  // Results = #6 
/*1208*/        OPC_EmitConvertToTarget, 4,
/*1210*/        OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::store_indirect), 0|OPFL_Chain,
                    0/*#VTs*/, 3/*#Ops*/, 1, 6, 7, 
                // Src: (PIC18F4455Store GR8:i8:$val, (MTLO:i8 GR8:i8:$loaddr), (MTHI:i8 GR8:i8:$hiaddr), (imm:i8):$offset) - Complexity = 12
                // Dst: (store_indirect GR8:i8:$val, (set_fsrhi:i16 (set_fsrlo:i16 GR8:i8:$loaddr), GR8:i8:$hiaddr), (imm:i8):$offset)
/*1219*/      0, /*End of Scope*/
/*1220*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 115,  TARGET_OPCODE(ISD::OR),// ->1339
/*1224*/    OPC_Scope, 44, /*->1270*/ // 3 children in Scope
/*1226*/      OPC_RecordChild0, // #0 = $src
/*1227*/      OPC_MoveChild, 1,
/*1229*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1232*/      OPC_RecordNode, // #1 = 'PIC18F4455Load' chained node
/*1233*/      OPC_CheckFoldableChainNode,
/*1234*/      OPC_RecordChild1, // #2 = $ptrlo
/*1235*/      OPC_RecordChild2, // #3 = $ptrhi
/*1236*/      OPC_MoveChild, 2,
/*1238*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1241*/      OPC_MoveParent,
/*1242*/      OPC_RecordChild3, // #4 = $offset
/*1243*/      OPC_MoveChild, 3,
/*1245*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1248*/      OPC_MoveParent,
/*1249*/      OPC_MoveParent,
/*1250*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectDirectAddr:$ptrlo #5
/*1253*/      OPC_EmitMergeInputChains1_1,
/*1254*/      OPC_EmitConvertToTarget, 4,
/*1256*/      OPC_EmitConvertToTarget, 3,
/*1258*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::OrFW), 0|OPFL_Chain,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 0, 6, 5, 7, 
              // Src: (or:i8 GR8:i8:$src, (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset)) - Complexity = 18
              // Dst: (OrFW:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*1270*/    /*Scope*/ 44, /*->1315*/
/*1271*/      OPC_MoveChild, 0,
/*1273*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1276*/      OPC_RecordNode, // #0 = 'PIC18F4455Load' chained node
/*1277*/      OPC_CheckFoldableChainNode,
/*1278*/      OPC_RecordChild1, // #1 = $ptrlo
/*1279*/      OPC_RecordChild2, // #2 = $ptrhi
/*1280*/      OPC_MoveChild, 2,
/*1282*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1285*/      OPC_MoveParent,
/*1286*/      OPC_RecordChild3, // #3 = $offset
/*1287*/      OPC_MoveChild, 3,
/*1289*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1292*/      OPC_MoveParent,
/*1293*/      OPC_MoveParent,
/*1294*/      OPC_RecordChild1, // #4 = $src
/*1295*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectDirectAddr:$ptrlo #5
/*1298*/      OPC_EmitMergeInputChains1_0,
/*1299*/      OPC_EmitConvertToTarget, 3,
/*1301*/      OPC_EmitConvertToTarget, 2,
/*1303*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::OrFW), 0|OPFL_Chain,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 4, 6, 5, 7, 
              // Src: (or:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src) - Complexity = 18
              // Dst: (OrFW:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*1315*/    /*Scope*/ 22, /*->1338*/
/*1316*/      OPC_RecordChild0, // #0 = $src
/*1317*/      OPC_RecordChild1, // #1 = $literal
/*1318*/      OPC_MoveChild, 1,
/*1320*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1323*/      OPC_MoveParent,
/*1324*/      OPC_CheckType, MVT::i8,
/*1326*/      OPC_EmitConvertToTarget, 1,
/*1328*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::orlw), 0,
                  2/*#VTs*/, MVT::i8, MVT::i8, 2/*#Ops*/, 0, 2, 
              // Src: (or:i8 GR8:i8:$src, (imm:i8):$literal) - Complexity = 6
              // Dst: (orlw:i8:i8 GR8:i8:$src, (imm:i8):$literal)
/*1338*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 115,  TARGET_OPCODE(ISD::XOR),// ->1457
/*1342*/    OPC_Scope, 44, /*->1388*/ // 3 children in Scope
/*1344*/      OPC_RecordChild0, // #0 = $src
/*1345*/      OPC_MoveChild, 1,
/*1347*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1350*/      OPC_RecordNode, // #1 = 'PIC18F4455Load' chained node
/*1351*/      OPC_CheckFoldableChainNode,
/*1352*/      OPC_RecordChild1, // #2 = $ptrlo
/*1353*/      OPC_RecordChild2, // #3 = $ptrhi
/*1354*/      OPC_MoveChild, 2,
/*1356*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1359*/      OPC_MoveParent,
/*1360*/      OPC_RecordChild3, // #4 = $offset
/*1361*/      OPC_MoveChild, 3,
/*1363*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1366*/      OPC_MoveParent,
/*1367*/      OPC_MoveParent,
/*1368*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectDirectAddr:$ptrlo #5
/*1371*/      OPC_EmitMergeInputChains1_1,
/*1372*/      OPC_EmitConvertToTarget, 4,
/*1374*/      OPC_EmitConvertToTarget, 3,
/*1376*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::XOrFW), 0|OPFL_Chain,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 0, 6, 5, 7, 
              // Src: (xor:i8 GR8:i8:$src, (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset)) - Complexity = 18
              // Dst: (XOrFW:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*1388*/    /*Scope*/ 44, /*->1433*/
/*1389*/      OPC_MoveChild, 0,
/*1391*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1394*/      OPC_RecordNode, // #0 = 'PIC18F4455Load' chained node
/*1395*/      OPC_CheckFoldableChainNode,
/*1396*/      OPC_RecordChild1, // #1 = $ptrlo
/*1397*/      OPC_RecordChild2, // #2 = $ptrhi
/*1398*/      OPC_MoveChild, 2,
/*1400*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1403*/      OPC_MoveParent,
/*1404*/      OPC_RecordChild3, // #3 = $offset
/*1405*/      OPC_MoveChild, 3,
/*1407*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1410*/      OPC_MoveParent,
/*1411*/      OPC_MoveParent,
/*1412*/      OPC_RecordChild1, // #4 = $src
/*1413*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectDirectAddr:$ptrlo #5
/*1416*/      OPC_EmitMergeInputChains1_0,
/*1417*/      OPC_EmitConvertToTarget, 3,
/*1419*/      OPC_EmitConvertToTarget, 2,
/*1421*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::XOrFW), 0|OPFL_Chain,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 4, 6, 5, 7, 
              // Src: (xor:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src) - Complexity = 18
              // Dst: (XOrFW:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*1433*/    /*Scope*/ 22, /*->1456*/
/*1434*/      OPC_RecordChild0, // #0 = $src
/*1435*/      OPC_RecordChild1, // #1 = $literal
/*1436*/      OPC_MoveChild, 1,
/*1438*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1441*/      OPC_MoveParent,
/*1442*/      OPC_CheckType, MVT::i8,
/*1444*/      OPC_EmitConvertToTarget, 1,
/*1446*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::xorlw), 0,
                  2/*#VTs*/, MVT::i8, MVT::i8, 2/*#Ops*/, 0, 2, 
              // Src: (xor:i8 GR8:i8:$src, (imm:i8):$literal) - Complexity = 6
              // Dst: (xorlw:i8:i8 GR8:i8:$src, (imm:i8):$literal)
/*1456*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 115,  TARGET_OPCODE(ISD::AND),// ->1575
/*1460*/    OPC_Scope, 44, /*->1506*/ // 3 children in Scope
/*1462*/      OPC_RecordChild0, // #0 = $src
/*1463*/      OPC_MoveChild, 1,
/*1465*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1468*/      OPC_RecordNode, // #1 = 'PIC18F4455Load' chained node
/*1469*/      OPC_CheckFoldableChainNode,
/*1470*/      OPC_RecordChild1, // #2 = $ptrlo
/*1471*/      OPC_RecordChild2, // #3 = $ptrhi
/*1472*/      OPC_MoveChild, 2,
/*1474*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1477*/      OPC_MoveParent,
/*1478*/      OPC_RecordChild3, // #4 = $offset
/*1479*/      OPC_MoveChild, 3,
/*1481*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1484*/      OPC_MoveParent,
/*1485*/      OPC_MoveParent,
/*1486*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectDirectAddr:$ptrlo #5
/*1489*/      OPC_EmitMergeInputChains1_1,
/*1490*/      OPC_EmitConvertToTarget, 4,
/*1492*/      OPC_EmitConvertToTarget, 3,
/*1494*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::AndFW), 0|OPFL_Chain,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 0, 6, 5, 7, 
              // Src: (and:i8 GR8:i8:$src, (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset)) - Complexity = 18
              // Dst: (AndFW:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*1506*/    /*Scope*/ 44, /*->1551*/
/*1507*/      OPC_MoveChild, 0,
/*1509*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1512*/      OPC_RecordNode, // #0 = 'PIC18F4455Load' chained node
/*1513*/      OPC_CheckFoldableChainNode,
/*1514*/      OPC_RecordChild1, // #1 = $ptrlo
/*1515*/      OPC_RecordChild2, // #2 = $ptrhi
/*1516*/      OPC_MoveChild, 2,
/*1518*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1521*/      OPC_MoveParent,
/*1522*/      OPC_RecordChild3, // #3 = $offset
/*1523*/      OPC_MoveChild, 3,
/*1525*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1528*/      OPC_MoveParent,
/*1529*/      OPC_MoveParent,
/*1530*/      OPC_RecordChild1, // #4 = $src
/*1531*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectDirectAddr:$ptrlo #5
/*1534*/      OPC_EmitMergeInputChains1_0,
/*1535*/      OPC_EmitConvertToTarget, 3,
/*1537*/      OPC_EmitConvertToTarget, 2,
/*1539*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::AndFW), 0|OPFL_Chain,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 4, 6, 5, 7, 
              // Src: (and:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src) - Complexity = 18
              // Dst: (AndFW:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*1551*/    /*Scope*/ 22, /*->1574*/
/*1552*/      OPC_RecordChild0, // #0 = $src
/*1553*/      OPC_RecordChild1, // #1 = $literal
/*1554*/      OPC_MoveChild, 1,
/*1556*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1559*/      OPC_MoveParent,
/*1560*/      OPC_CheckType, MVT::i8,
/*1562*/      OPC_EmitConvertToTarget, 1,
/*1564*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::andlw), 0,
                  2/*#VTs*/, MVT::i8, MVT::i8, 2/*#Ops*/, 0, 2, 
              // Src: (and:i8 GR8:i8:$src, (imm:i8):$literal) - Complexity = 6
              // Dst: (andlw:i8:i8 GR8:i8:$src, (imm:i8):$literal)
/*1574*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 115,  TARGET_OPCODE(ISD::ADD),// ->1693
/*1578*/    OPC_Scope, 44, /*->1624*/ // 3 children in Scope
/*1580*/      OPC_RecordChild0, // #0 = $src
/*1581*/      OPC_MoveChild, 1,
/*1583*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1586*/      OPC_RecordNode, // #1 = 'PIC18F4455Load' chained node
/*1587*/      OPC_CheckFoldableChainNode,
/*1588*/      OPC_RecordChild1, // #2 = $ptrlo
/*1589*/      OPC_RecordChild2, // #3 = $ptrhi
/*1590*/      OPC_MoveChild, 2,
/*1592*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1595*/      OPC_MoveParent,
/*1596*/      OPC_RecordChild3, // #4 = $offset
/*1597*/      OPC_MoveChild, 3,
/*1599*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1602*/      OPC_MoveParent,
/*1603*/      OPC_MoveParent,
/*1604*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectDirectAddr:$ptrlo #5
/*1607*/      OPC_EmitMergeInputChains1_1,
/*1608*/      OPC_EmitConvertToTarget, 4,
/*1610*/      OPC_EmitConvertToTarget, 3,
/*1612*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addfw_1), 0|OPFL_Chain,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 0, 6, 5, 7, 
              // Src: (add:i8 GR8:i8:$src, (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset)) - Complexity = 18
              // Dst: (addfw_1:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*1624*/    /*Scope*/ 44, /*->1669*/
/*1625*/      OPC_MoveChild, 0,
/*1627*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1630*/      OPC_RecordNode, // #0 = 'PIC18F4455Load' chained node
/*1631*/      OPC_CheckFoldableChainNode,
/*1632*/      OPC_RecordChild1, // #1 = $ptrlo
/*1633*/      OPC_RecordChild2, // #2 = $ptrhi
/*1634*/      OPC_MoveChild, 2,
/*1636*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1639*/      OPC_MoveParent,
/*1640*/      OPC_RecordChild3, // #3 = $offset
/*1641*/      OPC_MoveChild, 3,
/*1643*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1646*/      OPC_MoveParent,
/*1647*/      OPC_MoveParent,
/*1648*/      OPC_RecordChild1, // #4 = $src
/*1649*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectDirectAddr:$ptrlo #5
/*1652*/      OPC_EmitMergeInputChains1_0,
/*1653*/      OPC_EmitConvertToTarget, 3,
/*1655*/      OPC_EmitConvertToTarget, 2,
/*1657*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addfw_1), 0|OPFL_Chain,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 4, 6, 5, 7, 
              // Src: (add:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src) - Complexity = 18
              // Dst: (addfw_1:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*1669*/    /*Scope*/ 22, /*->1692*/
/*1670*/      OPC_RecordChild0, // #0 = $src
/*1671*/      OPC_RecordChild1, // #1 = $literal
/*1672*/      OPC_MoveChild, 1,
/*1674*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1677*/      OPC_MoveParent,
/*1678*/      OPC_CheckType, MVT::i8,
/*1680*/      OPC_EmitConvertToTarget, 1,
/*1682*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addlw_1), 0,
                  2/*#VTs*/, MVT::i8, MVT::i8, 2/*#Ops*/, 0, 2, 
              // Src: (add:i8 GR8:i8:$src, (imm:i8):$literal) - Complexity = 6
              // Dst: (addlw_1:i8:i8 GR8:i8:$src, (imm:i8):$literal)
/*1692*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 115,  TARGET_OPCODE(ISD::ADDC),// ->1811
/*1696*/    OPC_Scope, 44, /*->1742*/ // 3 children in Scope
/*1698*/      OPC_RecordChild0, // #0 = $src
/*1699*/      OPC_MoveChild, 1,
/*1701*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1704*/      OPC_RecordNode, // #1 = 'PIC18F4455Load' chained node
/*1705*/      OPC_CheckFoldableChainNode,
/*1706*/      OPC_RecordChild1, // #2 = $ptrlo
/*1707*/      OPC_RecordChild2, // #3 = $ptrhi
/*1708*/      OPC_MoveChild, 2,
/*1710*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1713*/      OPC_MoveParent,
/*1714*/      OPC_RecordChild3, // #4 = $offset
/*1715*/      OPC_MoveChild, 3,
/*1717*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1720*/      OPC_MoveParent,
/*1721*/      OPC_MoveParent,
/*1722*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectDirectAddr:$ptrlo #5
/*1725*/      OPC_EmitMergeInputChains1_1,
/*1726*/      OPC_EmitConvertToTarget, 4,
/*1728*/      OPC_EmitConvertToTarget, 3,
/*1730*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addfw_2), 0|OPFL_Chain|OPFL_FlagOutput,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 0, 6, 5, 7, 
              // Src: (addc:i8 GR8:i8:$src, (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset)) - Complexity = 18
              // Dst: (addfw_2:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*1742*/    /*Scope*/ 44, /*->1787*/
/*1743*/      OPC_MoveChild, 0,
/*1745*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1748*/      OPC_RecordNode, // #0 = 'PIC18F4455Load' chained node
/*1749*/      OPC_CheckFoldableChainNode,
/*1750*/      OPC_RecordChild1, // #1 = $ptrlo
/*1751*/      OPC_RecordChild2, // #2 = $ptrhi
/*1752*/      OPC_MoveChild, 2,
/*1754*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1757*/      OPC_MoveParent,
/*1758*/      OPC_RecordChild3, // #3 = $offset
/*1759*/      OPC_MoveChild, 3,
/*1761*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1764*/      OPC_MoveParent,
/*1765*/      OPC_MoveParent,
/*1766*/      OPC_RecordChild1, // #4 = $src
/*1767*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectDirectAddr:$ptrlo #5
/*1770*/      OPC_EmitMergeInputChains1_0,
/*1771*/      OPC_EmitConvertToTarget, 3,
/*1773*/      OPC_EmitConvertToTarget, 2,
/*1775*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addfw_2), 0|OPFL_Chain|OPFL_FlagOutput,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 4, 6, 5, 7, 
              // Src: (addc:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src) - Complexity = 18
              // Dst: (addfw_2:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*1787*/    /*Scope*/ 22, /*->1810*/
/*1788*/      OPC_RecordChild0, // #0 = $src
/*1789*/      OPC_RecordChild1, // #1 = $literal
/*1790*/      OPC_MoveChild, 1,
/*1792*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1795*/      OPC_MoveParent,
/*1796*/      OPC_CheckType, MVT::i8,
/*1798*/      OPC_EmitConvertToTarget, 1,
/*1800*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addlw_2), 0|OPFL_FlagOutput,
                  2/*#VTs*/, MVT::i8, MVT::i8, 2/*#Ops*/, 0, 2, 
              // Src: (addc:i8 GR8:i8:$src, (imm:i8):$literal) - Complexity = 6
              // Dst: (addlw_2:i8:i8 GR8:i8:$src, (imm:i8):$literal)
/*1810*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 116,  TARGET_OPCODE(ISD::ADDE),// ->1930
/*1814*/    OPC_CaptureFlagInput,
/*1815*/    OPC_Scope, 44, /*->1861*/ // 3 children in Scope
/*1817*/      OPC_RecordChild0, // #0 = $src
/*1818*/      OPC_MoveChild, 1,
/*1820*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1823*/      OPC_RecordNode, // #1 = 'PIC18F4455Load' chained node
/*1824*/      OPC_CheckFoldableChainNode,
/*1825*/      OPC_RecordChild1, // #2 = $ptrlo
/*1826*/      OPC_RecordChild2, // #3 = $ptrhi
/*1827*/      OPC_MoveChild, 2,
/*1829*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1832*/      OPC_MoveParent,
/*1833*/      OPC_RecordChild3, // #4 = $offset
/*1834*/      OPC_MoveChild, 3,
/*1836*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1839*/      OPC_MoveParent,
/*1840*/      OPC_MoveParent,
/*1841*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectDirectAddr:$ptrlo #5
/*1844*/      OPC_EmitMergeInputChains1_1,
/*1845*/      OPC_EmitConvertToTarget, 4,
/*1847*/      OPC_EmitConvertToTarget, 3,
/*1849*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addfwc), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 0, 6, 5, 7, 
              // Src: (adde:i8 GR8:i8:$src, (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset)) - Complexity = 18
              // Dst: (addfwc:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*1861*/    /*Scope*/ 44, /*->1906*/
/*1862*/      OPC_MoveChild, 0,
/*1864*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1867*/      OPC_RecordNode, // #0 = 'PIC18F4455Load' chained node
/*1868*/      OPC_CheckFoldableChainNode,
/*1869*/      OPC_RecordChild1, // #1 = $ptrlo
/*1870*/      OPC_RecordChild2, // #2 = $ptrhi
/*1871*/      OPC_MoveChild, 2,
/*1873*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1876*/      OPC_MoveParent,
/*1877*/      OPC_RecordChild3, // #3 = $offset
/*1878*/      OPC_MoveChild, 3,
/*1880*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1883*/      OPC_MoveParent,
/*1884*/      OPC_MoveParent,
/*1885*/      OPC_RecordChild1, // #4 = $src
/*1886*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectDirectAddr:$ptrlo #5
/*1889*/      OPC_EmitMergeInputChains1_0,
/*1890*/      OPC_EmitConvertToTarget, 3,
/*1892*/      OPC_EmitConvertToTarget, 2,
/*1894*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addfwc), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 4, 6, 5, 7, 
              // Src: (adde:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src) - Complexity = 18
              // Dst: (addfwc:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*1906*/    /*Scope*/ 22, /*->1929*/
/*1907*/      OPC_RecordChild0, // #0 = $src
/*1908*/      OPC_RecordChild1, // #1 = $literal
/*1909*/      OPC_MoveChild, 1,
/*1911*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1914*/      OPC_MoveParent,
/*1915*/      OPC_CheckType, MVT::i8,
/*1917*/      OPC_EmitConvertToTarget, 1,
/*1919*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::addlwc), 0|OPFL_FlagInput|OPFL_FlagOutput,
                  2/*#VTs*/, MVT::i8, MVT::i8, 2/*#Ops*/, 0, 2, 
              // Src: (adde:i8 GR8:i8:$src, (imm:i8):$literal) - Complexity = 6
              // Dst: (addlwc:i8:i8 GR8:i8:$src, (imm:i8):$literal)
/*1929*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 95,  TARGET_OPCODE(ISD::SUB),// ->2028
/*1933*/    OPC_Scope, 44, /*->1979*/ // 2 children in Scope
/*1935*/      OPC_MoveChild, 0,
/*1937*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*1940*/      OPC_RecordNode, // #0 = 'PIC18F4455Load' chained node
/*1941*/      OPC_CheckFoldableChainNode,
/*1942*/      OPC_RecordChild1, // #1 = $ptrlo
/*1943*/      OPC_RecordChild2, // #2 = $ptrhi
/*1944*/      OPC_MoveChild, 2,
/*1946*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1949*/      OPC_MoveParent,
/*1950*/      OPC_RecordChild3, // #3 = $offset
/*1951*/      OPC_MoveChild, 3,
/*1953*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1956*/      OPC_MoveParent,
/*1957*/      OPC_MoveParent,
/*1958*/      OPC_RecordChild1, // #4 = $src
/*1959*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectDirectAddr:$ptrlo #5
/*1962*/      OPC_EmitMergeInputChains1_0,
/*1963*/      OPC_EmitConvertToTarget, 3,
/*1965*/      OPC_EmitConvertToTarget, 2,
/*1967*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::subfw_1), 0|OPFL_Chain,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 4, 6, 5, 7, 
              // Src: (sub:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src) - Complexity = 18
              // Dst: (subfw_1:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*1979*/    /*Scope*/ 47, /*->2027*/
/*1980*/      OPC_RecordChild0, // #0 = $literal
/*1981*/      OPC_Scope, 21, /*->2004*/ // 2 children in Scope
/*1983*/        OPC_MoveChild, 0,
/*1985*/        OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*1988*/        OPC_MoveParent,
/*1989*/        OPC_RecordChild1, // #1 = $src
/*1990*/        OPC_CheckType, MVT::i8,
/*1992*/        OPC_EmitConvertToTarget, 0,
/*1994*/        OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::sublw_1), 0,
                    2/*#VTs*/, MVT::i8, MVT::i8, 2/*#Ops*/, 1, 2, 
                // Src: (sub:i8 (imm:i8):$literal, GR8:i8:$src) - Complexity = 6
                // Dst: (sublw_1:i8:i8 GR8:i8:$src, (imm:i8):$literal)
/*2004*/      /*Scope*/ 21, /*->2026*/
/*2005*/        OPC_RecordChild1, // #1 = $literal
/*2006*/        OPC_MoveChild, 1,
/*2008*/        OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2011*/        OPC_MoveParent,
/*2012*/        OPC_CheckType, MVT::i8,
/*2014*/        OPC_EmitConvertToTarget, 1,
/*2016*/        OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::sublw_4), 0,
                    2/*#VTs*/, MVT::i8, MVT::i8, 2/*#Ops*/, 0, 2, 
                // Src: (sub:i8 GR8:i8:$src, (imm:i8):$literal) - Complexity = 6
                // Dst: (sublw_4:i8:i8 GR8:i8:$src, (imm:i8):$literal)
/*2026*/      0, /*End of Scope*/
/*2027*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 95,  TARGET_OPCODE(ISD::SUBC),// ->2126
/*2031*/    OPC_Scope, 44, /*->2077*/ // 2 children in Scope
/*2033*/      OPC_MoveChild, 0,
/*2035*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*2038*/      OPC_RecordNode, // #0 = 'PIC18F4455Load' chained node
/*2039*/      OPC_CheckFoldableChainNode,
/*2040*/      OPC_RecordChild1, // #1 = $ptrlo
/*2041*/      OPC_RecordChild2, // #2 = $ptrhi
/*2042*/      OPC_MoveChild, 2,
/*2044*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2047*/      OPC_MoveParent,
/*2048*/      OPC_RecordChild3, // #3 = $offset
/*2049*/      OPC_MoveChild, 3,
/*2051*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2054*/      OPC_MoveParent,
/*2055*/      OPC_MoveParent,
/*2056*/      OPC_RecordChild1, // #4 = $src
/*2057*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectDirectAddr:$ptrlo #5
/*2060*/      OPC_EmitMergeInputChains1_0,
/*2061*/      OPC_EmitConvertToTarget, 3,
/*2063*/      OPC_EmitConvertToTarget, 2,
/*2065*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::subfw_2), 0|OPFL_Chain|OPFL_FlagOutput,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 4, 6, 5, 7, 
              // Src: (subc:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src) - Complexity = 18
              // Dst: (subfw_2:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*2077*/    /*Scope*/ 47, /*->2125*/
/*2078*/      OPC_RecordChild0, // #0 = $literal
/*2079*/      OPC_Scope, 21, /*->2102*/ // 2 children in Scope
/*2081*/        OPC_MoveChild, 0,
/*2083*/        OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2086*/        OPC_MoveParent,
/*2087*/        OPC_RecordChild1, // #1 = $src
/*2088*/        OPC_CheckType, MVT::i8,
/*2090*/        OPC_EmitConvertToTarget, 0,
/*2092*/        OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::sublw_2), 0|OPFL_FlagOutput,
                    2/*#VTs*/, MVT::i8, MVT::i8, 2/*#Ops*/, 1, 2, 
                // Src: (subc:i8 (imm:i8):$literal, GR8:i8:$src) - Complexity = 6
                // Dst: (sublw_2:i8:i8 GR8:i8:$src, (imm:i8):$literal)
/*2102*/      /*Scope*/ 21, /*->2124*/
/*2103*/        OPC_RecordChild1, // #1 = $literal
/*2104*/        OPC_MoveChild, 1,
/*2106*/        OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2109*/        OPC_MoveParent,
/*2110*/        OPC_CheckType, MVT::i8,
/*2112*/        OPC_EmitConvertToTarget, 1,
/*2114*/        OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::sublw_5), 0|OPFL_FlagOutput,
                    2/*#VTs*/, MVT::i8, MVT::i8, 2/*#Ops*/, 0, 2, 
                // Src: (subc:i8 GR8:i8:$src, (imm:i8):$literal) - Complexity = 6
                // Dst: (sublw_5:i8:i8 GR8:i8:$src, (imm:i8):$literal)
/*2124*/      0, /*End of Scope*/
/*2125*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 96,  TARGET_OPCODE(ISD::SUBE),// ->2225
/*2129*/    OPC_CaptureFlagInput,
/*2130*/    OPC_Scope, 44, /*->2176*/ // 2 children in Scope
/*2132*/      OPC_MoveChild, 0,
/*2134*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*2137*/      OPC_RecordNode, // #0 = 'PIC18F4455Load' chained node
/*2138*/      OPC_CheckFoldableChainNode,
/*2139*/      OPC_RecordChild1, // #1 = $ptrlo
/*2140*/      OPC_RecordChild2, // #2 = $ptrhi
/*2141*/      OPC_MoveChild, 2,
/*2143*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2146*/      OPC_MoveParent,
/*2147*/      OPC_RecordChild3, // #3 = $offset
/*2148*/      OPC_MoveChild, 3,
/*2150*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2153*/      OPC_MoveParent,
/*2154*/      OPC_MoveParent,
/*2155*/      OPC_RecordChild1, // #4 = $src
/*2156*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectDirectAddr:$ptrlo #5
/*2159*/      OPC_EmitMergeInputChains1_0,
/*2160*/      OPC_EmitConvertToTarget, 3,
/*2162*/      OPC_EmitConvertToTarget, 2,
/*2164*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::subfwb), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 4, 6, 5, 7, 
              // Src: (sube:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src) - Complexity = 18
              // Dst: (subfwb:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*2176*/    /*Scope*/ 47, /*->2224*/
/*2177*/      OPC_RecordChild0, // #0 = $literal
/*2178*/      OPC_Scope, 21, /*->2201*/ // 2 children in Scope
/*2180*/        OPC_MoveChild, 0,
/*2182*/        OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2185*/        OPC_MoveParent,
/*2186*/        OPC_RecordChild1, // #1 = $src
/*2187*/        OPC_CheckType, MVT::i8,
/*2189*/        OPC_EmitConvertToTarget, 0,
/*2191*/        OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::sublw_3), 0|OPFL_FlagInput|OPFL_FlagOutput,
                    2/*#VTs*/, MVT::i8, MVT::i8, 2/*#Ops*/, 1, 2, 
                // Src: (sube:i8 (imm:i8):$literal, GR8:i8:$src) - Complexity = 6
                // Dst: (sublw_3:i8:i8 GR8:i8:$src, (imm:i8):$literal)
/*2201*/      /*Scope*/ 21, /*->2223*/
/*2202*/        OPC_RecordChild1, // #1 = $literal
/*2203*/        OPC_MoveChild, 1,
/*2205*/        OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2208*/        OPC_MoveParent,
/*2209*/        OPC_CheckType, MVT::i8,
/*2211*/        OPC_EmitConvertToTarget, 1,
/*2213*/        OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::sublw_6), 0|OPFL_FlagInput|OPFL_FlagOutput,
                    2/*#VTs*/, MVT::i8, MVT::i8, 2/*#Ops*/, 0, 2, 
                // Src: (sube:i8 GR8:i8:$src, (imm:i8):$literal) - Complexity = 6
                // Dst: (sublw_6:i8:i8 GR8:i8:$src, (imm:i8):$literal)
/*2223*/      0, /*End of Scope*/
/*2224*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 68,  TARGET_OPCODE(PIC18F4455ISD::SUBCC),// ->2296
/*2228*/    OPC_Scope, 44, /*->2274*/ // 2 children in Scope
/*2230*/      OPC_MoveChild, 0,
/*2232*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),
/*2235*/      OPC_RecordNode, // #0 = 'PIC18F4455Load' chained node
/*2236*/      OPC_CheckFoldableChainNode,
/*2237*/      OPC_RecordChild1, // #1 = $ptrlo
/*2238*/      OPC_RecordChild2, // #2 = $ptrhi
/*2239*/      OPC_MoveChild, 2,
/*2241*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2244*/      OPC_MoveParent,
/*2245*/      OPC_RecordChild3, // #3 = $offset
/*2246*/      OPC_MoveChild, 3,
/*2248*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2251*/      OPC_MoveParent,
/*2252*/      OPC_MoveParent,
/*2253*/      OPC_RecordChild1, // #4 = $src
/*2254*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectDirectAddr:$ptrlo #5
/*2257*/      OPC_EmitMergeInputChains1_0,
/*2258*/      OPC_EmitConvertToTarget, 3,
/*2260*/      OPC_EmitConvertToTarget, 2,
/*2262*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::subfw_cc), 0|OPFL_Chain|OPFL_FlagOutput,
                  2/*#VTs*/, MVT::i8, MVT::i8, 4/*#Ops*/, 4, 6, 5, 7, 
              // Src: (PIC18F4455Subcc:i8 (PIC18F4455Load:i8 diraddr:i8:$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset), GR8:i8:$src) - Complexity = 18
              // Dst: (subfw_cc:i8:i8 GR8:i8:$src, (imm:i8):$offset, diraddr:i8:$ptrlo, (imm:i8):$ptrhi)
/*2274*/    /*Scope*/ 20, /*->2295*/
/*2275*/      OPC_RecordChild0, // #0 = $literal
/*2276*/      OPC_MoveChild, 0,
/*2278*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2281*/      OPC_MoveParent,
/*2282*/      OPC_RecordChild1, // #1 = $src
/*2283*/      OPC_EmitConvertToTarget, 0,
/*2285*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::sublw_cc), 0|OPFL_FlagOutput,
                  2/*#VTs*/, MVT::i8, MVT::i8, 2/*#Ops*/, 1, 2, 
              // Src: (PIC18F4455Subcc:i8 (imm:i8):$literal, GR8:i8:$src) - Complexity = 6
              // Dst: (sublw_cc:i8:i8 GR8:i8:$src, (imm:i8):$literal)
/*2295*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 93,  TARGET_OPCODE(PIC18F4455ISD::PIC18F4455StWF),// ->2392
/*2299*/    OPC_RecordNode,   // #0 = 'PIC18F4455StWF' chained node
/*2300*/    OPC_CaptureFlagInput,
/*2301*/    OPC_RecordChild1, // #1 = $val
/*2302*/    OPC_Scope, 36, /*->2340*/ // 2 children in Scope
/*2304*/      OPC_RecordChild2, // #2 = $ptrlo
/*2305*/      OPC_MoveChild, 2,
/*2307*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::TargetExternalSymbol),
/*2310*/      OPC_MoveParent,
/*2311*/      OPC_RecordChild3, // #3 = $ptrhi
/*2312*/      OPC_MoveChild, 3,
/*2314*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2317*/      OPC_MoveParent,
/*2318*/      OPC_RecordChild4, // #4 = $offset
/*2319*/      OPC_MoveChild, 4,
/*2321*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2324*/      OPC_MoveParent,
/*2325*/      OPC_EmitMergeInputChains1_0,
/*2326*/      OPC_EmitConvertToTarget, 4,
/*2328*/      OPC_EmitConvertToTarget, 3,
/*2330*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::movwf_2), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput,
                  0/*#VTs*/, 4/*#Ops*/, 1, 5, 2, 6, 
              // Src: (PIC18F4455StWF GR8:i8:$val, (texternalsym:i8):$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 12
              // Dst: (movwf_2 GR8:i8:$val, (imm:i8):$offset, (texternalsym:i8):$ptrlo, (imm:i8):$ptrhi)
/*2340*/    /*Scope*/ 50, /*->2391*/
/*2341*/      OPC_MoveChild, 2,
/*2343*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::MTLO),
/*2346*/      OPC_RecordChild0, // #2 = $loaddr
/*2347*/      OPC_MoveParent,
/*2348*/      OPC_MoveChild, 3,
/*2350*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::MTHI),
/*2353*/      OPC_RecordChild0, // #3 = $hiaddr
/*2354*/      OPC_MoveParent,
/*2355*/      OPC_RecordChild4, // #4 = $offset
/*2356*/      OPC_MoveChild, 4,
/*2358*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2361*/      OPC_MoveParent,
/*2362*/      OPC_EmitMergeInputChains1_0,
/*2363*/      OPC_EmitNode, TARGET_OPCODE(PIC18F4455::set_fsrlo), 0,
                  1/*#VTs*/, MVT::i16, 1/*#Ops*/, 2,  // Results = #5 
/*2371*/      OPC_EmitNode, TARGET_OPCODE(PIC18F4455::set_fsrhi), 0,
                  1/*#VTs*/, MVT::i16, 2/*#Ops*/, 5, 3,  // Results = #6 
/*2380*/      OPC_EmitConvertToTarget, 4,
/*2382*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::store_indirect), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput,
                  0/*#VTs*/, 3/*#Ops*/, 1, 6, 7, 
              // Src: (PIC18F4455StWF GR8:i8:$val, (MTLO:i8 GR8:i8:$loaddr), (MTHI:i8 GR8:i8:$hiaddr), (imm:i8):$offset) - Complexity = 12
              // Dst: (store_indirect GR8:i8:$val, (set_fsrhi:i16 (set_fsrlo:i16 GR8:i8:$loaddr), GR8:i8:$hiaddr), (imm:i8):$offset)
/*2391*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 0|128,1/*128*/,  TARGET_OPCODE(PIC18F4455ISD::PIC18F4455Load),// ->2524
/*2396*/    OPC_RecordNode,   // #0 = 'PIC18F4455Load' chained node
/*2397*/    OPC_Scope, 73, /*->2472*/ // 2 children in Scope
/*2399*/      OPC_RecordChild1, // #1 = $ptrlo
/*2400*/      OPC_MoveChild, 1,
/*2402*/      OPC_SwitchOpcode /*2 cases */, 31,  TARGET_OPCODE(ISD::TargetGlobalAddress),// ->2437
/*2406*/        OPC_MoveParent,
/*2407*/        OPC_RecordChild2, // #2 = $ptrhi
/*2408*/        OPC_MoveChild, 2,
/*2410*/        OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2413*/        OPC_MoveParent,
/*2414*/        OPC_RecordChild3, // #3 = $offset
/*2415*/        OPC_MoveChild, 3,
/*2417*/        OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2420*/        OPC_MoveParent,
/*2421*/        OPC_EmitMergeInputChains1_0,
/*2422*/        OPC_EmitConvertToTarget, 3,
/*2424*/        OPC_EmitConvertToTarget, 2,
/*2426*/        OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::movf), 0|OPFL_Chain,
                    2/*#VTs*/, MVT::i8, MVT::i8, 3/*#Ops*/, 4, 1, 5, 
                // Src: (PIC18F4455Load:i8 (tglobaladdr:i8):$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 12
                // Dst: (movf:i8:i8 (imm:i8):$offset, (tglobaladdr:i8):$ptrlo, (imm:i8):$ptrhi)
              /*SwitchOpcode*/ 31,  TARGET_OPCODE(ISD::TargetExternalSymbol),// ->2471
/*2440*/        OPC_MoveParent,
/*2441*/        OPC_RecordChild2, // #2 = $ptrhi
/*2442*/        OPC_MoveChild, 2,
/*2444*/        OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2447*/        OPC_MoveParent,
/*2448*/        OPC_RecordChild3, // #3 = $offset
/*2449*/        OPC_MoveChild, 3,
/*2451*/        OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2454*/        OPC_MoveParent,
/*2455*/        OPC_EmitMergeInputChains1_0,
/*2456*/        OPC_EmitConvertToTarget, 3,
/*2458*/        OPC_EmitConvertToTarget, 2,
/*2460*/        OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::movf_1), 0|OPFL_Chain,
                    2/*#VTs*/, MVT::i8, MVT::i8, 3/*#Ops*/, 4, 1, 5, 
                // Src: (PIC18F4455Load:i8 (texternalsym:i8):$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 12
                // Dst: (movf_1:i8:i8 (imm:i8):$offset, (texternalsym:i8):$ptrlo, (imm:i8):$ptrhi)
              0, // EndSwitchOpcode
/*2472*/    /*Scope*/ 50, /*->2523*/
/*2473*/      OPC_MoveChild, 1,
/*2475*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::MTLO),
/*2478*/      OPC_RecordChild0, // #1 = $loaddr
/*2479*/      OPC_MoveParent,
/*2480*/      OPC_MoveChild, 2,
/*2482*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::MTHI),
/*2485*/      OPC_RecordChild0, // #2 = $hiaddr
/*2486*/      OPC_MoveParent,
/*2487*/      OPC_RecordChild3, // #3 = $offset
/*2488*/      OPC_MoveChild, 3,
/*2490*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2493*/      OPC_MoveParent,
/*2494*/      OPC_EmitMergeInputChains1_0,
/*2495*/      OPC_EmitNode, TARGET_OPCODE(PIC18F4455::set_fsrlo), 0,
                  1/*#VTs*/, MVT::i16, 1/*#Ops*/, 1,  // Results = #4 
/*2503*/      OPC_EmitNode, TARGET_OPCODE(PIC18F4455::set_fsrhi), 0,
                  1/*#VTs*/, MVT::i16, 2/*#Ops*/, 4, 2,  // Results = #5 
/*2512*/      OPC_EmitConvertToTarget, 3,
/*2514*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::load_indirect), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i8, 2/*#Ops*/, 5, 6, 
              // Src: (PIC18F4455Load:i8 (MTLO:i8 GR8:i8:$loaddr), (MTHI:i8 GR8:i8:$hiaddr), (imm:i8):$offset) - Complexity = 12
              // Dst: (load_indirect:i8 (set_fsrhi:i16 (set_fsrlo:i16 GR8:i8:$loaddr), GR8:i8:$hiaddr), (imm:i8):$offset)
/*2523*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 38,  TARGET_OPCODE(PIC18F4455ISD::PIC18F4455LdArg),// ->2565
/*2527*/    OPC_RecordNode,   // #0 = 'PIC18F4455LdArg' chained node
/*2528*/    OPC_RecordChild1, // #1 = $ptrlo
/*2529*/    OPC_MoveChild, 1,
/*2531*/    OPC_CheckOpcode, TARGET_OPCODE(ISD::TargetExternalSymbol),
/*2534*/    OPC_MoveParent,
/*2535*/    OPC_RecordChild2, // #2 = $ptrhi
/*2536*/    OPC_MoveChild, 2,
/*2538*/    OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2541*/    OPC_MoveParent,
/*2542*/    OPC_RecordChild3, // #3 = $offset
/*2543*/    OPC_MoveChild, 3,
/*2545*/    OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2548*/    OPC_MoveParent,
/*2549*/    OPC_EmitMergeInputChains1_0,
/*2550*/    OPC_EmitConvertToTarget, 3,
/*2552*/    OPC_EmitConvertToTarget, 2,
/*2554*/    OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::movf_1_1), 0|OPFL_Chain,
                2/*#VTs*/, MVT::i8, MVT::i8, 3/*#Ops*/, 4, 1, 5, 
            // Src: (PIC18F4455LdArg:i8 (texternalsym:i8):$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 12
            // Dst: (movf_1_1:i8:i8 (imm:i8):$offset, (texternalsym:i8):$ptrlo, (imm:i8):$ptrhi)
          /*SwitchOpcode*/ 93,  TARGET_OPCODE(PIC18F4455ISD::PIC18F4455LdWF),// ->2661
/*2568*/    OPC_RecordNode,   // #0 = 'PIC18F4455LdWF' chained node
/*2569*/    OPC_CaptureFlagInput,
/*2570*/    OPC_Scope, 37, /*->2609*/ // 2 children in Scope
/*2572*/      OPC_RecordChild1, // #1 = $ptrlo
/*2573*/      OPC_MoveChild, 1,
/*2575*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::TargetExternalSymbol),
/*2578*/      OPC_MoveParent,
/*2579*/      OPC_RecordChild2, // #2 = $ptrhi
/*2580*/      OPC_MoveChild, 2,
/*2582*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2585*/      OPC_MoveParent,
/*2586*/      OPC_RecordChild3, // #3 = $offset
/*2587*/      OPC_MoveChild, 3,
/*2589*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2592*/      OPC_MoveParent,
/*2593*/      OPC_EmitMergeInputChains1_0,
/*2594*/      OPC_EmitConvertToTarget, 3,
/*2596*/      OPC_EmitConvertToTarget, 2,
/*2598*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::movf_2), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput,
                  2/*#VTs*/, MVT::i8, MVT::i8, 3/*#Ops*/, 4, 1, 5, 
              // Src: (PIC18F4455LdWF:i8 (texternalsym:i8):$ptrlo, (imm:i8):$ptrhi, (imm:i8):$offset) - Complexity = 12
              // Dst: (movf_2:i8:i8 (imm:i8):$offset, (texternalsym:i8):$ptrlo, (imm:i8):$ptrhi)
/*2609*/    /*Scope*/ 50, /*->2660*/
/*2610*/      OPC_MoveChild, 1,
/*2612*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::MTLO),
/*2615*/      OPC_RecordChild0, // #1 = $loaddr
/*2616*/      OPC_MoveParent,
/*2617*/      OPC_MoveChild, 2,
/*2619*/      OPC_CheckOpcode, TARGET_OPCODE(PIC18F4455ISD::MTHI),
/*2622*/      OPC_RecordChild0, // #2 = $hiaddr
/*2623*/      OPC_MoveParent,
/*2624*/      OPC_RecordChild3, // #3 = $offset
/*2625*/      OPC_MoveChild, 3,
/*2627*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2630*/      OPC_MoveParent,
/*2631*/      OPC_EmitMergeInputChains1_0,
/*2632*/      OPC_EmitNode, TARGET_OPCODE(PIC18F4455::set_fsrlo), 0,
                  1/*#VTs*/, MVT::i16, 1/*#Ops*/, 1,  // Results = #4 
/*2640*/      OPC_EmitNode, TARGET_OPCODE(PIC18F4455::set_fsrhi), 0,
                  1/*#VTs*/, MVT::i16, 2/*#Ops*/, 4, 2,  // Results = #5 
/*2649*/      OPC_EmitConvertToTarget, 3,
/*2651*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::load_indirect), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput,
                  1/*#VTs*/, MVT::i8, 2/*#Ops*/, 5, 6, 
              // Src: (PIC18F4455LdWF:i8 (MTLO:i8 GR8:i8:$loaddr), (MTHI:i8 GR8:i8:$hiaddr), (imm:i8):$offset) - Complexity = 12
              // Dst: (load_indirect:i8 (set_fsrhi:i16 (set_fsrlo:i16 GR8:i8:$loaddr), GR8:i8:$hiaddr), (imm:i8):$offset)
/*2660*/    0, /*End of Scope*/
          /*SwitchOpcode*/ 26,  TARGET_OPCODE(ISD::CALLSEQ_END),// ->2690
/*2664*/    OPC_RecordNode,   // #0 = 'PIC18F4455callseq_end' chained node
/*2665*/    OPC_CaptureFlagInput,
/*2666*/    OPC_RecordChild1, // #1 = $amt1
/*2667*/    OPC_MoveChild, 1,
/*2669*/    OPC_CheckOpcode, TARGET_OPCODE(ISD::TargetConstant),
/*2672*/    OPC_MoveParent,
/*2673*/    OPC_RecordChild2, // #2 = $amt2
/*2674*/    OPC_MoveChild, 2,
/*2676*/    OPC_CheckOpcode, TARGET_OPCODE(ISD::TargetConstant),
/*2679*/    OPC_MoveParent,
/*2680*/    OPC_EmitMergeInputChains1_0,
/*2681*/    OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput,
                1/*#VTs*/, MVT::i16, 2/*#Ops*/, 1, 2, 
            // Src: (PIC18F4455callseq_end (timm:i8):$amt1, (timm:i8):$amt2) - Complexity = 9
            // Dst: (ADJCALLSTACKUP:i16 (timm:i8):$amt1, (timm:i8):$amt2)
          /*SwitchOpcode*/ 49,  TARGET_OPCODE(PIC18F4455ISD::Lo),// ->2742
/*2693*/    OPC_RecordChild0, // #0 = $src
/*2694*/    OPC_MoveChild, 0,
/*2696*/    OPC_SwitchOpcode /*2 cases */, 19,  TARGET_OPCODE(ISD::TargetGlobalAddress),// ->2719
/*2700*/      OPC_MoveParent,
/*2701*/      OPC_RecordChild1, // #1 = $src2
/*2702*/      OPC_MoveChild, 1,
/*2704*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2707*/      OPC_MoveParent,
/*2708*/      OPC_EmitConvertToTarget, 1,
/*2710*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::movlw_lo_1), 0,
                  1/*#VTs*/, MVT::i8, 2/*#Ops*/, 0, 2, 
              // Src: (PIC18F4455Lo:i8 (tglobaladdr:i8):$src, (imm:i8):$src2) - Complexity = 9
              // Dst: (movlw_lo_1:i8 (tglobaladdr:i8):$src, (imm:i8):$src2)
            /*SwitchOpcode*/ 19,  TARGET_OPCODE(ISD::TargetExternalSymbol),// ->2741
/*2722*/      OPC_MoveParent,
/*2723*/      OPC_RecordChild1, // #1 = $src2
/*2724*/      OPC_MoveChild, 1,
/*2726*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2729*/      OPC_MoveParent,
/*2730*/      OPC_EmitConvertToTarget, 1,
/*2732*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::movlw_lo_2), 0,
                  1/*#VTs*/, MVT::i8, 2/*#Ops*/, 0, 2, 
              // Src: (PIC18F4455Lo:i8 (texternalsym:i8):$src, (imm:i8):$src2) - Complexity = 9
              // Dst: (movlw_lo_2:i8 (texternalsym:i8):$src, (imm:i8):$src2)
            0, // EndSwitchOpcode
          /*SwitchOpcode*/ 49,  TARGET_OPCODE(PIC18F4455ISD::Hi),// ->2794
/*2745*/    OPC_RecordChild0, // #0 = $src
/*2746*/    OPC_MoveChild, 0,
/*2748*/    OPC_SwitchOpcode /*2 cases */, 19,  TARGET_OPCODE(ISD::TargetGlobalAddress),// ->2771
/*2752*/      OPC_MoveParent,
/*2753*/      OPC_RecordChild1, // #1 = $src2
/*2754*/      OPC_MoveChild, 1,
/*2756*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2759*/      OPC_MoveParent,
/*2760*/      OPC_EmitConvertToTarget, 1,
/*2762*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::movlw_hi_1), 0,
                  1/*#VTs*/, MVT::i8, 2/*#Ops*/, 0, 2, 
              // Src: (PIC18F4455Hi:i8 (tglobaladdr:i8):$src, (imm:i8):$src2) - Complexity = 9
              // Dst: (movlw_hi_1:i8 (tglobaladdr:i8):$src, (imm:i8):$src2)
            /*SwitchOpcode*/ 19,  TARGET_OPCODE(ISD::TargetExternalSymbol),// ->2793
/*2774*/      OPC_MoveParent,
/*2775*/      OPC_RecordChild1, // #1 = $src2
/*2776*/      OPC_MoveChild, 1,
/*2778*/      OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2781*/      OPC_MoveParent,
/*2782*/      OPC_EmitConvertToTarget, 1,
/*2784*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::movlw_hi_2), 0,
                  1/*#VTs*/, MVT::i8, 2/*#Ops*/, 0, 2, 
              // Src: (PIC18F4455Hi:i8 (texternalsym:i8):$src, (imm:i8):$src2) - Complexity = 9
              // Dst: (movlw_hi_2:i8 (texternalsym:i8):$src, (imm:i8):$src2)
            0, // EndSwitchOpcode
          /*SwitchOpcode*/ 17,  TARGET_OPCODE(ISD::CALLSEQ_START),// ->2814
/*2797*/    OPC_RecordNode,   // #0 = 'PIC18F4455callseq_start' chained node
/*2798*/    OPC_RecordChild1, // #1 = $amt
/*2799*/    OPC_MoveChild, 1,
/*2801*/    OPC_CheckOpcode, TARGET_OPCODE(ISD::TargetConstant),
/*2804*/    OPC_MoveParent,
/*2805*/    OPC_EmitMergeInputChains1_0,
/*2806*/    OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_FlagOutput,
                1/*#VTs*/, MVT::i16, 1/*#Ops*/, 1, 
            // Src: (PIC18F4455callseq_start (timm:i8):$amt) - Complexity = 6
            // Dst: (ADJCALLSTACKDOWN:i16 (timm:i8):$amt)
          /*SwitchOpcode*/ 49,  TARGET_OPCODE(PIC18F4455ISD::CALL),// ->2866
/*2817*/    OPC_RecordNode,   // #0 = 'PIC18F4455call' chained node
/*2818*/    OPC_CaptureFlagInput,
/*2819*/    OPC_RecordChild1, // #1 = $function
/*2820*/    OPC_MoveChild, 1,
/*2822*/    OPC_SwitchOpcode /*3 cases */, 11,  TARGET_OPCODE(ISD::Constant),// ->2837
/*2826*/      OPC_MoveParent,
/*2827*/      OPC_EmitMergeInputChains1_0,
/*2828*/      OPC_EmitConvertToTarget, 1,
/*2830*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::CALL), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput|OPFL_Variadic1,
                  0/*#VTs*/, 1/*#Ops*/, 2, 
              // Src: (PIC18F4455call (imm:iPTR):$function) - Complexity = 6
              // Dst: (CALL (imm:i16):$function)
            /*SwitchOpcode*/ 11,  TARGET_OPCODE(ISD::TargetGlobalAddress),// ->2851
/*2840*/      OPC_CheckType, MVT::i16,
/*2842*/      OPC_MoveParent,
/*2843*/      OPC_EmitMergeInputChains1_0,
/*2844*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::CALL), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput|OPFL_Variadic1,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (PIC18F4455call (tglobaladdr:i16):$dst) - Complexity = 6
              // Dst: (CALL (tglobaladdr:i16):$dst)
            /*SwitchOpcode*/ 11,  TARGET_OPCODE(ISD::TargetExternalSymbol),// ->2865
/*2854*/      OPC_CheckType, MVT::i16,
/*2856*/      OPC_MoveParent,
/*2857*/      OPC_EmitMergeInputChains1_0,
/*2858*/      OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::CALL), 0|OPFL_Chain|OPFL_FlagInput|OPFL_FlagOutput|OPFL_Variadic1,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (PIC18F4455call (texternalsym:i16):$dst) - Complexity = 6
              // Dst: (CALL (texternalsym:i16):$dst)
            0, // EndSwitchOpcode
          /*SwitchOpcode*/ 27,  TARGET_OPCODE(PIC18F4455ISD::BRCOND),// ->2896
/*2869*/    OPC_RecordNode,   // #0 = 'PIC18F4455Brcond' chained node
/*2870*/    OPC_CaptureFlagInput,
/*2871*/    OPC_RecordChild1, // #1 = $dst
/*2872*/    OPC_MoveChild, 1,
/*2874*/    OPC_CheckOpcode, TARGET_OPCODE(ISD::BasicBlock),
/*2877*/    OPC_MoveParent,
/*2878*/    OPC_RecordChild2, // #2 = $cc
/*2879*/    OPC_MoveChild, 2,
/*2881*/    OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2884*/    OPC_MoveParent,
/*2885*/    OPC_EmitMergeInputChains1_0,
/*2886*/    OPC_EmitConvertToTarget, 2,
/*2888*/    OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::pic18f4455brcond), 0|OPFL_Chain|OPFL_FlagInput,
                0/*#VTs*/, 2/*#Ops*/, 1, 3, 
            // Src: (PIC18F4455Brcond (bb:Other):$dst, (imm:i8):$cc) - Complexity = 6
            // Dst: (pic18f4455brcond (bb:Other):$dst, (imm:i8):$cc)
          /*SwitchOpcode*/ 18,  TARGET_OPCODE(PIC18F4455ISD::RETLW),// ->2917
/*2899*/    OPC_RecordNode,   // #0 = 'PIC18F4455retlw' chained node
/*2900*/    OPC_RecordChild1, // #1 = $literal
/*2901*/    OPC_MoveChild, 1,
/*2903*/    OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2906*/    OPC_MoveParent,
/*2907*/    OPC_EmitMergeInputChains1_0,
/*2908*/    OPC_EmitConvertToTarget, 1,
/*2910*/    OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::Retlw), 0|OPFL_Chain,
                0/*#VTs*/, 1/*#Ops*/, 2, 
            // Src: (PIC18F4455retlw (imm:i8):$literal) - Complexity = 6
            // Dst: (Retlw (imm:i8):$literal)
          /*SwitchOpcode*/ 22,  TARGET_OPCODE(PIC18F4455ISD::SELECT_ICC),// ->2942
/*2920*/    OPC_CaptureFlagInput,
/*2921*/    OPC_RecordChild0, // #0 = $T
/*2922*/    OPC_RecordChild1, // #1 = $F
/*2923*/    OPC_RecordChild2, // #2 = $Cond
/*2924*/    OPC_MoveChild, 2,
/*2926*/    OPC_CheckOpcode, TARGET_OPCODE(ISD::Constant),
/*2929*/    OPC_MoveParent,
/*2930*/    OPC_EmitConvertToTarget, 2,
/*2932*/    OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::SELECT_CC_Int_ICC), 0|OPFL_FlagInput,
                1/*#VTs*/, MVT::i8, 3/*#Ops*/, 0, 1, 3, 
            // Src: (PIC18F4455Selecticc:i8 GR8:i8:$T, GR8:i8:$F, (imm:i8):$Cond) - Complexity = 6
            // Dst: (SELECT_CC_Int_ICC:i8 GR8:i8:$T, GR8:i8:$F, (imm:i8):$Cond)
          /*SwitchOpcode*/ 13,  TARGET_OPCODE(ISD::Constant),// ->2958
/*2945*/    OPC_RecordNode,   // #0 = $src
/*2946*/    OPC_CheckType, MVT::i8,
/*2948*/    OPC_EmitConvertToTarget, 0,
/*2950*/    OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::movlw), 0,
                1/*#VTs*/, MVT::i8, 1/*#Ops*/, 1, 
            // Src: (imm:i8):$src - Complexity = 3
            // Dst: (movlw:i8 (imm:i8):$src)
          /*SwitchOpcode*/ 9,  TARGET_OPCODE(PIC18F4455ISD::MTPCLATH),// ->2970
/*2961*/    OPC_RecordChild0, // #0 = $val
/*2962*/    OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::set_pclath), 0,
                1/*#VTs*/, MVT::i8, 1/*#Ops*/, 0, 
            // Src: (MTPCLATH:i8 GR8:i8:$val) - Complexity = 3
            // Dst: (set_pclath:i8 GR8:i8:$val)
          /*SwitchOpcode*/ 16,  TARGET_OPCODE(ISD::BR),// ->2989
/*2973*/    OPC_RecordNode,   // #0 = 'br' chained node
/*2974*/    OPC_RecordChild1, // #1 = $dst
/*2975*/    OPC_MoveChild, 1,
/*2977*/    OPC_CheckOpcode, TARGET_OPCODE(ISD::BasicBlock),
/*2980*/    OPC_MoveParent,
/*2981*/    OPC_EmitMergeInputChains1_0,
/*2982*/    OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::br_uncond), 0|OPFL_Chain,
                0/*#VTs*/, 1/*#Ops*/, 1, 
            // Src: (br (bb:Other):$dst) - Complexity = 3
            // Dst: (br_uncond (bb:Other):$dst)
          /*SwitchOpcode*/ 8,  TARGET_OPCODE(PIC18F4455ISD::RET),// ->3000
/*2992*/    OPC_RecordNode,   // #0 = 'PIC18F4455ret' chained node
/*2993*/    OPC_EmitMergeInputChains1_0,
/*2994*/    OPC_MorphNodeTo, TARGET_OPCODE(PIC18F4455::Return), 0|OPFL_Chain,
                0/*#VTs*/, 0/*#Ops*/, 
            // Src: (PIC18F4455ret) - Complexity = 3
            // Dst: (Return)
          0, // EndSwitchOpcode
    0
  }; // Total Array size is 3002 bytes

  // Opcode Histogram:
  // #OPC_Scope                          = 24
  // #OPC_RecordNode                     = 50
  // #OPC_RecordChild                    = 202
  // #OPC_RecordMemRef                   = 0
  // #OPC_CaptureFlagInput               = 10
  // #OPC_MoveChild                      = 204
  // #OPC_MoveParent                     = 225
  // #OPC_CheckSame                      = 48
  // #OPC_CheckPatternPredicate          = 0
  // #OPC_CheckPredicate                 = 0
  // #OPC_CheckOpcode                    = 150
  // #OPC_SwitchOpcode                   = 7
  // #OPC_CheckType                      = 15
  // #OPC_SwitchType                     = 0
  // #OPC_CheckChildType                 = 0
  // #OPC_CheckInteger                   = 0
  // #OPC_CheckCondCode                  = 0
  // #OPC_CheckValueType                 = 0
  // #OPC_CheckComplexPat                = 32
  // #OPC_CheckAndImm                    = 0
  // #OPC_CheckOrImm                     = 0
  // #OPC_CheckFoldableChainNode         = 32
  // #OPC_EmitInteger                    = 0
  // #OPC_EmitStringInteger              = 0
  // #OPC_EmitRegister                   = 0
  // #OPC_EmitConvertToTarget            = 104
  // #OPC_EmitMergeInputChains           = 52
  // #OPC_EmitCopyToReg                  = 0
  // #OPC_EmitNode                       = 8
  // #OPC_EmitNodeXForm                  = 0
  // #OPC_MarkFlagResults                = 7
  // #OPC_CompleteMatch                  = 0
  // #OPC_MorphNodeTo                    = 72

  #undef TARGET_OPCODE
  return SelectCodeCommon(N, MatcherTable,sizeof(MatcherTable));
}

bool CheckComplexPattern(SDNode *Root, SDValue N,
      unsigned PatternNo, SmallVectorImpl<SDValue> &Result) {
  unsigned NextRes = Result.size();
  switch (PatternNo) {
  default: assert(0 && "Invalid pattern # in table?");
  case 0:
    Result.resize(NextRes+1);
    return SelectDirectAddr(Root, N, Result[NextRes+0]);
  }
}


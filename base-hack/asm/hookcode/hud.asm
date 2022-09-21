CoinHUDReposition:
    ADDIU	t8, r0, 0x26
    LUI 	t7, hi(CurrentMap)
    LW 		t7, lo(CurrentMap) (t7)
    ADDIU 	a2, r0, 1
    BEQ 	t7, a2, CoinHUDReposition_Finish
    NOP
    ADDIU 	a2, r0, 5
    BEQ 	t7, a2, CoinHUDReposition_Finish
    NOP
    ADDIU 	a2, r0, 0x19
    BEQ 	t7, a2, CoinHUDReposition_Finish
    NOP

    CoinHUDReposition_Lower:
        ADDIU 	t8, r0, 0x4C

    CoinHUDReposition_Finish:
        J 	0x806F88D0
        ADDIU 	t7, r0, 0x122

GiveItemPointerToMulti:
    LUI 	t8, hi(MultiBunchCount)
    ADDIU 	t8, t8, lo(MultiBunchCount)
    SW 		t8, 0x0 (s0)
    J 		0x806F8618
    SW 		t6, 0xC (s0)

TextHandler:
    LUI 	t9, hi(PauseText)
    LBU 	t9, lo(PauseText) (t9)
    BEQZ 	t9, TextHandler_NoPause
    NOP

    TextHandler_Pause:
        J 	0x8070E8B8
        NOP

    TextHandler_NoPause:
        LW 	t9, 0x60 (a1)
        J 	0x8070E844
        LUI at, 0xFDFF

InvertCameraControls:
    ADDU 	t7, t7, t6
    LB 		t7, 0xD63F (t7)
    LUI 	a0, hi(InvertedControls)
    LBU 	a0, lo(InvertedControls) (a0)
    BEQZ 	a0, InvertCameraControls_Finish
    NOP
    SUB 	t7, r0, t7

    InvertCameraControls_Finish:
        J 	0x806EA714
        NOP

HUDDisplayCode:
    ADDIU 		a0, sp, 0x6C
    SW 			s0, 0x10 (sp)
    JAL 		writeHUDAmount
    LW 	 		a3, 0x78 (sp)
    J 			0x806F9F90
    OR 			s0, v0, r0

HomingDisable:
    LBU 		t1, 0x2 (t0)
    LUI			t2, hi(ForceStandardAmmo)
    LBU 		t2, lo(ForceStandardAmmo) (t2)
    BEQZ 		t2, HomingDisable_Finish
    NOP
    LUI 		t2, hi(ToggleAmmoOn)
    LBU 		t2, lo(ToggleAmmoOn) (t2)
    BEQZ 		t2, HomingDisable_Finish
    NOP
    ANDI 		t1, t1, 0xFFFD

    HomingDisable_Finish:
        J 		0x806E22B8
        ANDI 	t2, t1, 0x2

HomingHUDHandle:
    LUI 		a0, hi(ForceStandardAmmo)
    LBU 		a0, lo(ForceStandardAmmo) (a0)
    BEQZ 		a0, HomingHUDHandle_Finish
    NOP
    ADDIU 		a3, r0, 0x2

    HomingHUDHandle_Finish:
        OR 			a0, a3, r0
        J 			0x806EB57C
        OR 			a1, r0, r0
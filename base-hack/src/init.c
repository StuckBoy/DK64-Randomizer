#include "../include/common.h"

static const char exittoisles[] = "EXIT TO ISLES";

void initHack(void) {
	if ((LoadedHooks == 0) && (CurrentMap == 0x28)) {
		DebugInfoOn = 1;
		*(int*)(0x80731F78) = 0; // Debug 1 Column
		*(int*)(0x8060E04C) = 0; // Prevent moves overwrite
		*(short*)(0x8060DDAA) = 0; // Writes readfile data to moves
		*(short*)(0x806C9CDE) = 7; // GiveEverything, write to bitfield. Seems to be unused but might as well
		// Strong Kong
		*(int*)(0x8067ECFC) = 0x30810002; // ANDI $at $a0 2
		*(int*)(0x8067ED00) = 0x50200003; // BEQL $at $r0 3
		// Rocketbarrel
		*(int*)(0x80682024) = 0x31810002; // ANDI $at $t4 2
		*(int*)(0x80682028) = 0x50200006; // BEQL $at $r0 0x6
		// OSprint
		*(int*)(0x8067ECE0) = 0x30810004; // ANDI $at $a0 4
		*(int*)(0x8067ECE4) = 0x10200002; // BEQZ $at, 2
		// Mini Monkey
		*(int*)(0x8067EC80) = 0x30830001; // ANDI $v1 $a0 1
		*(int*)(0x8067EC84) = 0x18600002; // BLEZ $v1 2
		// Hunky Chunky (Not Dogadon)
		*(int*)(0x8067ECA0) = 0x30810001; // ANDI $at $a0 1
		*(int*)(0x8067ECA4) = 0x18200002; // BLEZ $at 2
		// PTT
		*(int*)(0x806E20F0) = 0x31010002; // ANDI $at $t0 2
		*(int*)(0x806E20F4) = 0x5020000F; // BEQL $at $r0 0xF
		// PPUnch
		*(int*)(0x806E48F4) = 0x31810002; // ANDI $at $t4 2
		*(int*)(0x806E48F8) = 0x50200074; // BEQL $at $r0 0xF
		DamageMultiplier = Rando.damage_multiplier;
		WarpToIslesEnabled = Rando.warp_to_isles_enabled;
		permaLossMode = Rando.perma_lose_kongs;
		disableBossKongCheck = Rando.disable_boss_kong_check;
		preventTagSpawn = Rando.prevent_tag_spawn;
		bonusAutocomplete = Rando.resolve_bonus;
		changeCharSpawnerFlag(0x14, 2, 93); // Tie llama spawn to lanky help me cutscene flag
		if (Rando.no_health_refill) {
			*(int*)(0x80683A34) = 0; // Cancel Tag Health Refill
			// *(int*)(0x8060DD10) = 0; // Load File
			// *(int*)(0x806C8010) = 0; // Load into map with < 1 health
			// *(int*)(0x806C94E4) = 0; // ?
			// *(int*)(0x806C9BC0) = 0; // Multiplayer
			*(int*)(0x806CB340) = 0; // Voiding
			*(int*)(0x806DEFE4) = 0; // Fairies
			// *(int*)(0x80708C9C) = 0; // Bonus Barrels (Taking Damge) & Watermelons
			// *(int*)(0x80708CA4) = 0; // Bonus Barrels (Full Health) & Watermelons
			*(int*)(0x806A6EA8) = 0; // Bonus Barrels
		}
		if (Rando.resolve_bonus & 1) {
			*(short*)(0x806818DE) = 0x4248; // Make Aztec Lobby GB spawn above the trapdoor)
			*(int*)(0x80681690) = 0; // Make some barrels not play a cutscene
		}
		replace_zones(1);
		randomize_bosses();
		loadExtraHooks();
		no_enemy_drops();
		// Moves & Prices
		replace_moves();
		price_rando();
		if (!Rando.move_rando_on) {
			moveTransplant();
			if (!Rando.price_rando_on) {
				priceTransplant();
			}
		}
		// Style 6 Mtx
		int base_mtx = 75;
		style6Mtx[0x0] = base_mtx;
		style6Mtx[0x5] = base_mtx;
		style6Mtx[0xF] = 100;
		base_mtx = 12;
		style2Mtx[0x0] = base_mtx;
		style2Mtx[0x5] = base_mtx;
		style2Mtx[0xF] = 10;
		if (Rando.warp_to_isles_enabled) {
			// Pause Menu Exit To Isles Slot
			*(short*)(0x806A85EE) = 4; // Yes/No Prompt
			*(short*)(0x806A8716) = 4; // Yes/No Prompt
			//*(short*)(0x806A87BE) = 3;
			*(short*)(0x806A880E) = 4; // Yes/No Prompt
			//*(short*)(0x806A8766) = 4;
			*(short*)(0x806A986A) = 4; // Yes/No Prompt
			*(int*)(0x806A9990) = 0x2A210270; // SLTI $at, $s1, 0x2A8
			PauseSlot3TextPointer = (char*)&exittoisles;
		}
		// Object Instance Scripts
		*(int*)(0x80748064) = (int)&change_object_scripts;
		// Sniper Scope Check
		*(int*)(0x806D2988) = 0x93190002; // LBU $t9, 0x2 ($t8)
		*(int*)(0x806D2990) = 0x33210004; // ANDI $at, $t9, 0x4
		*(short*)(0x806D299C) = 0x1020; // BEQ $at, $r0
		// Speedy T&S Turn-Ins
		*(int*)(0x806BE3E0) = 0; // NOP
		// EEPROM Patch
		*(int*)(0x8060D588) = 0; // NOP
		LoadedHooks = 1;
	}
}
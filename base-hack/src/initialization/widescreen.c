/**
 * @file widescreen.c
 * @author Gamemasterplc, Ballaam
 * @brief Ported from the Widescreen DK64 Hack by Gamemasterplc (https://patch.wedarobi.com/dk_widescreen)
 * @version 0.1
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../../include/common.h"

void ws_boot(void) {

}

#define GFX_START 0x807FF100
void ws_Gfx(void) {
    *(short*)(GFX_START + 0x00) = (SCREEN_WD*2); //2D Viewport Width
    *(short*)(GFX_START + 0x08) = (SCREEN_WD*2); //2D Viewport X Position
    *(int*)(GFX_START + 0x9C) = ((SCREEN_WD << 14)|(240 << 2)); //Default Scissor for 2D
}

static double pos_center_4x = SCREEN_WD_FLOAT * 2;
static double pos_center = SCREEN_WD_FLOAT / 2;
#define ZIPPER_COLOR_VALUE 0xFFFF

void ws_fillzipperwhite(void* write_ptr, void* framebuffer) {
    int px_clear = SCREEN_WD * 240;
    int write = (int)write_ptr;
    for (int i = 0; i < px_clear; i++) {
        *(short*)(write) = ZIPPER_COLOR_VALUE;
        write += 2;
    }
}

void ws_static(void) {
    *(short*)(0x805FB982) = 1; // Disable High Resolution for MAP_NINTENDOLOGO
    *(int*)(0x805FB9F8) = 0x24190000 | (SCREEN_WD-1); //Scissor Width for Jetpac and DK Arcade
    *(int*)(0x805FBB04) = 0x24090000 | (SCREEN_WD-11); //Scissor Right Edge for Game
    *(int*)(0x805FBBF4) = 0x24180000 | SCREEN_WD; //Screen Width for Framebuffer
    *(int*)(0x805FBC24) = 0x24040000; //Remove Black Bars
    int framebuffer_clear = SCREEN_WD * 240;
    int framebuffer_size = framebuffer_clear << 2;
    *(int*)(0x80610378) = 0x3C0F0000 | ((framebuffer_size >> 16) & 0xFFFF); //Load Size of Framebuffer 
    *(int*)(0x8061037C) = 0x35EF0000 | (framebuffer_size & 0xFFFF); //Load Size of Framebuffer
    *(short*)(0x80610956) = (framebuffer_clear >> 16) & 0xFFFF; //Upper Half of Framebuffer Clear Length
    *(short*)(0x80610962) = framebuffer_clear & 0xFFFF; //Lower Half of Framebuffer Clear Length
    *(short*)(0x80629292) = SCREEN_WD - 10; //X Position of Transition from Right
    *(short*)(0x806292A2) = SCREEN_WD / 2; //X Position of Double Transition
    *(short*)(0x80629626) = SCREEN_WD; // Pause Menu Texture Width
    *(short*)(0x806296F6) = SCREEN_WD; // Pause Menu Texture Width 2
    *(short*)(0x806297E6) = SCREEN_WD; // Pause Menu Texture Width 3
    *(short*)(0x806298BA) = SCREEN_WD; // Pause Menu Texture Width 4
    *(short*)(0x80629902) = SCREEN_WD - 9; // Maximum X Position of Transitions
    *(short*)(0x8062999E) = SCREEN_WD; // Pause Menu Texture Width 5
    *(short*)(0x806299EE) = SCREEN_WD - 15; // Maximum X Position of Transitions 2
    *(short*)(0x80629A5A) = SCREEN_WD; // Pause Menu Texture Width 6
    *(short*)(0x80629B4A) = SCREEN_WD; // Pause Menu Texture Width 7
    *(short*)(0x80629BAA) = SCREEN_WD; // Pause Menu Texture Width 8
    *(short*)(0x80629C6A) = SCREEN_WD; // Pause Menu Texture Width 9
    *(short*)(0x80629C9E) = SCREEN_WD - 15; // Maximum X Position of Transitions 3
    *(short*)(0x80629D06) = SCREEN_WD; // Pause Menu Texture Width 10
    *(short*)(0x80629D5E) = SCREEN_WD - 9; // Maximum X Position of Transitions 4
    *(short*)(0x80629E46) = SCREEN_WD; // Pause Menu Texture Width 10
    *(short*)(0x80629F6E) = SCREEN_WD; // Pause Menu Texture Width 11
    *(short*)(0x8062A07E) = SCREEN_WD; // Pause Menu Texture Width 12
    
    float temp = SCREEN_WD;
    *(short*)(0x80629E26) = *(short*)(&temp); // Width of Transitions 5
    *(short*)(0x80629F4E) = *(short*)(&temp); // Width of Transitions 6
    *(short*)(0x8062A00E) = *(short*)(&temp); // Width of Transitions 7

    *(short*)(0x8068D98E) = SCREEN_WD - 40; //X Position of Camera Icon
    *(short*)(0x8069FCAA) = SCREEN_WD; //Screen Width for Large Words
    temp = SCREEN_WD >> 1;
    *(short*)(0x8069D9F6) = *(short*)(&temp); // X Position of Bending Text
    *(short*)(0x8069DA2A) = *(short*)(&temp); // X Position of Bending Text 2
    *(short*)(0x806C7852) = *(short*)(&temp); //X Position of Top Credits
    *(short*)(0x806C7882) = *(short*)(&temp); //X Position of Bottom Credits

    temp = SCREEN_WD << 1;
    *(short*)(0x8069FF5E) = *(short*)(&temp); // X Position of Round Number
    
    *(short*)(0x806ACB4E) = (SCREEN_WD * 2) - 280; //X Position of Try Again Text
    *(short*)(0x806ACB9E) = (SCREEN_WD * 2) - 120; //X Position of Yes Text
    *(short*)(0x806ACBE2) = (SCREEN_WD * 2) - 120; //X Position of No Text
    *(short*)(0x806ACF76) = SCREEN_WD << 1; //X Position of Multiplayer Pause Menu Return
    *(short*)(0x806ACFDE) = SCREEN_WD << 1; //X Position of Multiplayer Pause Menu Quit Game
    *(int*)(0x806FD4C4) = 0x25D00000 | (((SCREEN_WD / 2) - 160) & 0xFFFF); // X Offset of Text
    *(short*)(0x806FF0F2) = SCREEN_WD / 2; //X Position of Cannon Cursor
    *(int*)(0x807095F4) = 0x24030140; //Force Zipper Transition Width
    *(int*)(0x806AC3E4) = 0x3C010000 | getHi(&pos_center_4x); //Load High Half of pos_center_4x
    *(int*)(0x806AC3E8) = 0xD4280000 | getLo(&pos_center_4x); //Load pos_center_4x
    *(int*)(0x806AC3EC) = 0x46020102; //Run Replaced Instruction

    int noise_scissor = ((SCREEN_WD - 11) << 14) | (229 << 2);
    *(short*)(0x8070368A) = (noise_scissor >> 16) & 0xFFFF; //Upper Part of Noise Scissor
    *(short*)(0x8070369A) = noise_scissor & 0xFFFF; //Lower Part of Noise Scissor
    int noise_scissor_gfx = 0xF6000000 | ((SCREEN_WD - 11) << 14);
    *(short*)(0x807036AE) = (noise_scissor_gfx >> 16) & 0xFFFF; //Upper Part of Noise Rectangle
    *(short*)(0x807036B2) = noise_scissor_gfx & 0xFFFF; //Lower Part of Noise Rectangle

    *(short*)(0x806A94AE) = SCREEN_WD; //Max X Position of UI Elements
    /*
        .org 0x806FF3A8
        addiu t3, r0, ((SCREEN_WD/2)-80) //X Position of Upper-Left of Capture Marker

        .org 0x806FF3EC
        addiu t7, r0, ((SCREEN_WD/2)+80) //X Position of Upper-Right of Capture Marker

        .org 0x806FF434
        addiu t2, r0, ((SCREEN_WD/2)+80) //X Position of Lower-Right of Capture Marker

        .org 0x806FF47C
        addiu t7, r0, ((SCREEN_WD/2)-80) //X Position of Lower-Left of Capture Marker

        .org 0x806FF4CC
        addiu t2, r0, (SCREEN_WD/2) //X Position of Capture Center

        .org 0x806FF564
        addiu t2, r0, (SCREEN_WD-40) //X Position of Sad Face

        .org 0x806FF5D0
        addiu t8, r0, (SCREEN_WD-40) //X Position of Happy Face

        .org 0x806FF690
        addiu t2, r0, (SCREEN_WD/2) //X Position of Picture X Sign

        .org 0x806FF708
        addiu t8, r0, (SCREEN_WD/2) //X Position of Picture Check Sign

        .org 0x806FFAD4
        addiu t0, r0, (SCREEN_WD/2) //X Position of Scope Cursor
    */
    temp = SCREEN_WD_FLOAT / 63;
    *(short*)(0x806FFBA6) = *(short*)(&temp); //Fix Camera Transition
    *(short*)(0x806FFBBA) = SCREEN_WD / 2; //X Position of Circle Transition
    *(int*)(0x8070F308) = 0x08000000 | ((((int)(fixTilePosition)) & 0xFFFFFF) >> 2);
    // writeFunction(0x8070AFD0, ws_fillzipperwhite);
    *(short*)(0x807075EE) = (SCREEN_WD / 128) + 2; //Number of Tiles Rendered in Main Menu Background
    *(short*)(0x80708906) = SCREEN_WD << 1; //X Position of Melons in UI
    *(short*)(0x807098D2) = 0xE08; //Double a Structure Size for Zipper
    *(short*)(0x80709F5E) = SCREEN_WD - 1; //Width of Zipper Fade Texture
    *(short*)(0x80700012) = ((SCREEN_WD / 2) - 80) * 2; //Source Offset for Camera Picture Copy
    float width = (SCREEN_WD_FLOAT * 460) / 320;
    *(short*)(0x80706D26) = *(short*)(&width); //Background Width in Snide Race
    float zipper_aspect_ratio = SCREEN_WD_FLOAT / 240;
    int zipper_aspect_ratio_int = *(int*)(&zipper_aspect_ratio);
    *(short*)(0x8070ADC6) = (zipper_aspect_ratio_int >> 16) & 0xFFFF;
    *(short*)(0x8070ADCA) = zipper_aspect_ratio_int & 0xFFFF;

    int zipper_scissor = ((SCREEN_WD - 11) << 14) | (229 << 2);
    *(short*)(0x8070AE02) = (zipper_scissor >> 16) & 0xFFFF; //Upper Part of Zipper Transition Scissor
    *(short*)(0x8070AE0E) = zipper_scissor & 0xFFFF; //Lower Part of Zipper Transition Scissor
    *(short*)(0x8070BFA6) = 0xE400 | ((SCREEN_WD / 8) + 2); //Zipper Right Edge X Position
    *(short*)(0x8070C07E) = (SCREEN_WD/8)-2; //Zipper Left Edge X Position
    *(short*)(0x8070FCA6) = SCREEN_WD; //Max X Position of Reset Banana in Storm
    *(short*)(0x80712112) = SCREEN_WD; //Screen Range of Banana Storm
    int transition_scissor = ((SCREEN_WD - 11) << 14) | (229 << 2);
    *(short*)(0x8071331E) = (transition_scissor >> 16) & 0xFFFF; //Upper Part of Transition Scissor
    *(short*)(0x8071334A) = transition_scissor & 0xFFFF; //Lower Part of Transition Scissor
    *(short*)(0x8071390A) = SCREEN_WD - 11; //Viewport Width of Transitions
    *(short*)(0x80713C46) = SCREEN_WD << 1; //X Position of Game Over Text
    *(int*)(0x80714B58) = 0x24190000 | (SCREEN_WD-11); //Scissor Width of UI
   
    float d_x = (SCREEN_WD_FLOAT*2)-190;
    int d_x_int = *(int*)(&d_x);
    *(int*)(0x80728E08) = 0x3C0D0000 | ((d_x_int >> 16) & 0xFFFF); //X Position of D Letter in Intro
    *(int*)(0x80728E0C) = 0x35AD0000 | (d_x_int & 0xFFFF); //X Position of D Letter in Intro
    *(int*)(0x80728E1C) = 0xAD8D007C; //Write X Position of D Letter in Intro

    d_x = (SCREEN_WD_FLOAT*2)+180;
    d_x_int = *(int*)(&d_x);
    *(int*)(0x80728E38) = 0x3C190000 | ((d_x_int >> 16) & 0xFFFF); //X Position of K Letter in Intro
    *(int*)(0x80728E3C) = 0x37390000 | (d_x_int & 0xFFFF); //X Position of K Letter in Intro
    *(int*)(0x80728E4C) = 0xAF19007C; //Write X Position of K Letter in Intro
    d_x = (SCREEN_WD * 2) - 140;
    *(int*)(0x80728E88) = 0x3C0F0000 | *(short*)(&d_x); //X Position of Round Text
    *(int*)(0x80728EA0) = 0xADCF007C; //Write X Position of Round Text

    *(short*)(0x8062A8C8) = 0x1000; // Disable Anamorphic Widescreen

    *(short*)(0x806A965A) = (SCREEN_WD*2); //X Position of Melons
    *(short*)(0x806A9836) = (SCREEN_WD*2); //X Position of Are You Sure Text
    *(short*)(0x806A993A) = (SCREEN_WD*2); //X Position of Pause Menu Options
    *(short*)(0x806A9A0A) = (SCREEN_WD*2); //X Position of Pause Menu Yes Option
    *(short*)(0x806A9A42) = (SCREEN_WD*2); //X Position of Pause Menu No Option
    *(short*)(0x806A9B6A) = (SCREEN_WD*2); //X Position of DK Isles Icons
    *(short*)(0x806A9CA6) = ((SCREEN_WD*2)+40); //X Position of Banana Count
    *(short*)(0x806A9ED6) = ((SCREEN_WD*2)+48); //X Position of Banana Count
    *(short*)(0x806A9F6A) = (SCREEN_WD*2); //X Position of Golden Bananas Text
    *(short*)(0x806A9F92) = (SCREEN_WD*2); //X Position of Totals Text
    *(short*)(0x806A9FB6) = (SCREEN_WD*2); //X Position of Total Golden Banana Count

    *(short*)(0x806AA6AA) = (SCREEN_WD-30); //X Position of Coin Counter
    *(short*)(0x806AA6DE) = (SCREEN_WD-30); //X Position of Coin Icon
    *(short*)(0x806AA6F6) = (SCREEN_WD-30); //X Position of Drum Counter
    *(short*)(0x806AA752) = (SCREEN_WD-30); //X Position of Drum Icon
    *(short*)(0x806AA796) = (SCREEN_WD-30); //X Position of Film Reel Counter
    *(short*)(0x806AA7CA) = (SCREEN_WD-30); //X Position of Film Reel Icon
    *(short*)(0x806AA7E6) = ((SCREEN_WD/2)-15); //X Position of Golden Banana Counter
    *(short*)(0x806AA832) = ((SCREEN_WD/2)-15); //X Position of Golden Banana Icon
    *(short*)(0x806AAACE) = ((SCREEN_WD/2)-15); //X Position of Golden Banana Icon
    *(short*)(0x806AAC1E) = (SCREEN_WD/2); //X Position of Analog Stick on Character Wheel
    *(short*)(0x806AAFA6) = (SCREEN_WD/2); //X Position of Crown
    *(short*)(0x806AB036) = (SCREEN_WD-60); //X Position of Fairy 2 on Kongs Screen
    *(short*)(0x806AB1B2) = (SCREEN_WD-60); //X Position of Fairy 3 on Maps
    *(short*)(0x806AB1EE) = (SCREEN_WD-70); //X Position of Fairy 4 on Maps
    *(short*)(0x806AB22A) = ((SCREEN_WD/2)-15); //X Position of Golden Banana Icon
    *(short*)(0x806AB42E) = (SCREEN_WD/2); //X Position of Totals Screen X Position
    *(short*)(0x806AB4BE) = (SCREEN_WD-45); //X Position of R Button
    d_x = SCREEN_WD_FLOAT * 2;
    *(short*)(0x806AB682) = *(short*)(&d_x); //Max X Position of UI Icon Slide Out
    *(short*)(0x806AB916) = *(short*)(&d_x); //Max X Position of UI Slide Out
    *(short*)(0x806ABB12) = SCREEN_WD * 2; //X Position of Level Name
    *(short*)(0x806ABB42) = SCREEN_WD * 2; //X Position of Level Icon
}

void ws_staticdata(void) {
    *(float*)(0x807444BC) = SCREEN_WD_FLOAT / 240; //Aspect Ratio of Help Text
    *(double*)(0x8075ACD0) = (SCREEN_WD_FLOAT * 2) - 40; //X Position of Up C Button
    *(double*)(0x8075ACD8) = (SCREEN_WD_FLOAT * 2) + 40; //X Position of Down C Button
    *(double*)(0x8075C408) = SCREEN_WD_FLOAT + 70; //X Offset of Player Names for Credits Right
    *(int*)(0x80747B30) = SCREEN_WD; //Blurring Process Pitch
    *(short*)(0x80750240) = SCREEN_WD; //Sand Effect Vertex 2 X
    *(short*)(0x80750248) = ((SCREEN_WD*2016)/320); //Sand Effect Vertex 2 X Texcoord
    *(short*)(0x80750250) = SCREEN_WD; //Sand Effect Vertex 3 X
    *(short*)(0x80750258) = ((SCREEN_WD*2016)/320); //Sand Effect Vertex 3 X Texcoord
    *(short*)(0x80750848) = (SCREEN_WD-1); //Right Edge of Blackness in Border 1
    *(short*)(0x8075085C) = (SCREEN_WD-11); //Left Edge of Blackness in Border 3
    *(short*)(0x80750860) = (SCREEN_WD-1); //Right Edge of Blackness in Border 3
    *(short*)(0x8075086C) = (SCREEN_WD-11); //Right Edge of Blackness in Border 4
    *(short*)(0x80750878) = (SCREEN_WD-1); //Right Edge of Blackness in Border 5
    *(short*)(0x8075088C) = (SCREEN_WD-13); //Left Edge of Blackness in Border 7
    *(short*)(0x80750890) = (SCREEN_WD-1); //Right Edge of Blackness in Border 7
    *(short*)(0x8075089C) = (SCREEN_WD-13); //Right Edge of Blackness in Border 8
    *(short*)(0x807508A8) = (SCREEN_WD-14); //Right Edge of Blackness in Border 9
    *(short*)(0x807508B0) = ((SCREEN_WD/2)-1); //Left Edge of Blackness in Border 10
    *(short*)(0x807508B4) = ((SCREEN_WD/2)+1); //Right Edge of Blackness in Border 11
    *(short*)(0x807508BC) = ((SCREEN_WD/2)-1); //Left Edge of Blackness in Border 12
    *(short*)(0x807508C0) = (SCREEN_WD-14); //Right Edge of Blackness in Border 12
    *(short*)(0x807508CC) = ((SCREEN_WD/2)+1); //Right Edge of Blackness in Border 13
    *(short*)(0x807508D8) = SCREEN_WD; //Right Edge of Blackness in Border 14
    *(short*)(0x807508E0) = ((SCREEN_WD/2)-1); //Left Edge of Blackness in Border 15
    *(short*)(0x807508E4) = ((SCREEN_WD/2)+1); //Right Edge of Blackness in Border 15
    *(short*)(0x807508EC) = ((SCREEN_WD/2)-1); //Left Edge of Blackness in Border 16
    *(short*)(0x807508F0) = (SCREEN_WD-14); //Right Edge of Blackness in Border 16
    *(short*)(0x807508F8) = ((SCREEN_WD/2)-1); //Left Edge of Blackness in Border 17
    *(short*)(0x807508FC) = (SCREEN_WD-14); //Right Edge of Blackness in Border 17
    *(short*)(0x80750904) = ((SCREEN_WD/2)-1); //Left Edge of Blackness in Border 18
    *(short*)(0x80750908) = ((SCREEN_WD/2)+1); //Right Edge of Blackness in Border 18
    *(short*)(0x80750914) = (SCREEN_WD-14); //Left Edge of Blackness in Border 19
    *(short*)(0x8075091C) = ((SCREEN_WD/2)-1); //Left Edge of Blackness in Border 20
    *(short*)(0x80750920) = ((SCREEN_WD/2)+1); //Right Edge of Blackness in Border 20
    *(short*)(0x8075092C) = (SCREEN_WD-14); //Left Edge of Blackness in Border 21
    *(short*)(0x80750934) = ((SCREEN_WD/2)-1); //Left Edge of Blackness in Border 22
    *(short*)(0x80750938) = ((SCREEN_WD/2)+1); //Right Edge of Blackness in Border 22

    *(short*)(0x80750950) = (SCREEN_WD-11); //Right Edge of Viewport Setup 1
    *(short*)(0x8075095C) = (SCREEN_WD-11); //Right Edge of Viewport Setup 2
    *(short*)(0x80750968) = (SCREEN_WD-13); //Right Edge of Viewport Setup 3
    *(short*)(0x80750974) = (SCREEN_WD-13); //Right Edge of Viewport Setup 4
    *(short*)(0x80750980) = ((SCREEN_WD/2)-1); //Right Edge of Viewport Setup 5
    *(short*)(0x80750988) = ((SCREEN_WD/2)+1); //Left Edge of Viewport Setup 6
    *(short*)(0x8075098C) = (SCREEN_WD-13); //Right Edge of Viewport Setup 6
    *(short*)(0x80750998) = ((SCREEN_WD/2)-1); //Right Edge of Viewport Setup 7
    *(short*)(0x807509A0) = ((SCREEN_WD/2)+1); //Left Edge of Viewport Setup 8
    *(short*)(0x807509A4) = (SCREEN_WD-13); //Right Edge of Viewport Setup 8
    *(short*)(0x807509B0) = (SCREEN_WD-13); //Right Edge of Viewport Setup 9
    *(short*)(0x807509BC) = (SCREEN_WD-13); //Right Edge of Viewport Setup 10
    *(short*)(0x807509C8) = ((SCREEN_WD/2)-1); //Right Edge of Viewport Setup 11
    *(short*)(0x807509D0) = ((SCREEN_WD/2)+1); //Left Edge of Viewport Setup 12
    *(short*)(0x807509D4) = (SCREEN_WD-13); //Right Edge of Viewport Setup 12
    *(short*)(0x807509E0) = ((SCREEN_WD/2)-1); //Right Edge of Viewport Setup 13
    *(short*)(0x807509EC) = ((SCREEN_WD/2)-1); //Right Edge of Viewport Setup 14
    *(short*)(0x807509F4) = ((SCREEN_WD/2)+1); //Left Edge of Viewport Setup 15
    *(short*)(0x807509F8) = (SCREEN_WD-13); //Right Edge of Viewport Setup 15
    *(short*)(0x80750A00) = ((SCREEN_WD/2)+1); //Left Edge of Viewport Setup 16
    *(short*)(0x80750A04) = (SCREEN_WD-13); //Right Edge of Viewport Setup 16
    *(short*)(0x80750A10) = (SCREEN_WD-13); //Right Edge of Viewport Setup 17
    *(short*)(0x80750A1C) = ((SCREEN_WD/2)-1); //Right Edge of Viewport Setup 18
    *(short*)(0x80750A24) = ((SCREEN_WD/2)+1); //Left Edge of Viewport Setup 19
    *(short*)(0x80750A28) = (SCREEN_WD-13); //Right Edge of Viewport Setup 19
    *(short*)(0x80750A34) = (SCREEN_WD-13); //Right Edge of Viewport Setup 20
    *(short*)(0x80750A40) = (SCREEN_WD-13); //Right Edge of Viewport Setup 21
    *(short*)(0x80750A4C) = (SCREEN_WD-13); //Right Edge of Viewport Setup 22
    *(short*)(0x80750A58) = ((SCREEN_WD/2)-1); //Right Edge of Viewport Setup 23
    *(short*)(0x80750A60) = ((SCREEN_WD/2)+1); //Left Edge of Viewport Setup 24
    *(short*)(0x80750A64) = (SCREEN_WD-13); //Right Edge of Viewport Setup 24
    *(short*)(0x80750A70) = ((SCREEN_WD/2)-1); //Right Edge of Viewport Setup 25
    *(short*)(0x80750A78) = ((SCREEN_WD/2)+1); //Left Edge of Viewport Setup 26
    *(short*)(0x80750A7C) = (SCREEN_WD-13); //Right Edge of Viewport Setup 26
    *(short*)(0x80750A88) = (SCREEN_WD-13); //Right Edge of Viewport Setup 27
    *(short*)(0x80750A94) = (SCREEN_WD-13); //Right Edge of Viewport Setup 28
    *(short*)(0x80750AA0) = (SCREEN_WD-13); //Right Edge of Viewport Setup 29
    *(short*)(0x80750AAC) = (SCREEN_WD-13); //Right Edge of Viewport Setup 30
    *(short*)(0x80754C08) = -((SCREEN_WD*128)/320); //Position of Vertex 1 of Transition
    *(short*)(0x80754C0A) = -((SCREEN_WD*128)/320); //Position of Vertex 1 of Transition
    *(short*)(0x80754C18) = ((SCREEN_WD*128)/320); //Position of Vertex 2 of Transition
    *(short*)(0x80754C1A) = -((SCREEN_WD*128)/320); //Position of Vertex 2 of Transition
    *(short*)(0x80754C28) = ((SCREEN_WD*128)/320); //Position of Vertex 3 of Transition
    *(short*)(0x80754C2A) = ((SCREEN_WD*128)/320); //Position of Vertex 3 of Transition
    *(short*)(0x80754C38) = -((SCREEN_WD*128)/320); //Position of Vertex 4 of Transition
    *(short*)(0x80754C3A) = ((SCREEN_WD*128)/320); //Position of Vertex 4 of Transition
    *(float*)(0x8075E4D8) = SCREEN_WD - 5.0f; //Max X Position of Banana in Storm
    *(short*)(0x80754C58) = SCREEN_WD; //X Position of Vertex 2 of UI Layer 1
    *(short*)(0x80754C68) = SCREEN_WD; //X Position of Vertex 3 of UI Layer 1
    *(short*)(0x80754C98) = SCREEN_WD; //X Position of Vertex 2 of UI Layer 2
    *(short*)(0x80754CA8) = SCREEN_WD; //X Position of Vertex 3 of UI Layer 2
    *(float*)(0x80758140) = SCREEN_WD - 1.0f; // X Size of Pause Menu Background Texture 1
    *(float*)(0x80758144) = SCREEN_WD - 1.0f; // X Size of Pause Menu Background Texture 1
    *(float*)(0x80758148) = SCREEN_WD - 1.0f; // X Size of Pause Menu Background Texture 1
    *(float*)(0x8075814C) = SCREEN_WD - 1.0f; // X Size of Pause Menu Background Texture 1
}

void ws_minigame(void) {
    *(short*)(0x80027396) = SCREEN_WD - 40; // X Position of Melons
    *(short*)(0x8002D1B2) = SCREEN_WD << 1; // X Position of HIT and Combo Text
}

void ws_arcade(void) {
    int clear_rect_instruction = 0xF6000000 | ((SCREEN_WD-1) << 14) | (239 << 2); // Clear Rectangle for DK Arcade
    *(short*)(0x800242E6) = (clear_rect_instruction >> 16) & 0xFFFF;
    *(short*)(0x800242EA) = clear_rect_instruction & 0xFFFF;
    int scissor = ((SCREEN_WD - 48) << 14)|(232 << 2);
    *(short*)(0x80025B16) = getUpper(scissor); // Scissor Higher Half for DK Arcade
    *(short*)(0x80025B22) = getLower(scissor); //Scissor Lower Half for DK Arcade
    int scissor_rect = (SCREEN_WD << 14) | (240 << 2); // Scissor Rectangle for DK Arcade
    *(short*)(0x800319E6) = getUpper(scissor_rect);
    *(short*)(0x800319EA) = getLower(scissor_rect);
}

void ws_jetpac(void) {
    int clear_rect_instruction = 0xF6000000 | ((SCREEN_WD-1) << 14) | (239 << 2);
    *(short*)(0x800242CE) = (clear_rect_instruction >> 16) & 0xFFFF; //Clear Rectangle for Jetpac High Half
    *(short*)(0x800242EA) = clear_rect_instruction & 0xFFFF; //Clear Rectangle for Jetpac Low Half
    int scissor = ((SCREEN_WD - 32) << 14) | (216 << 2);
    *(short*)(0x800255F2) = (scissor >> 16) & 0xFFFF; // Scissor Higher Half for Jetpac
    *(short*)(0x800255FE) = scissor & 0xFFFF; //Scissor Lower Half for Jetpac
}

void ws_menu(void) {
    *(short*)(0x80024632) = (SCREEN_WD*2); //X Position of Blueprint Names
    *(short*)(0x800246AA) = ((SCREEN_WD*2)-290); //X Position of Blueprints Text
    *(short*)(0x800246F2) = ((SCREEN_WD*2)-290); //X Position of Exit Text
    *(short*)(0x80024742) = ((SCREEN_WD*2)-290); //X Position of Bonus Text
    *(short*)(0x80024FF2) = ((SCREEN_WD/2)-120); //X Position of Left Edge of Chart Blackness
    *(short*)(0x80024FF6) = ((SCREEN_WD/2)-90); //X Position of Right Edge of Chart Blackness
    *(short*)(0x80025CA2) = ((SCREEN_WD*2)-140); //X Position of Yes Text for DK Arcade
    *(short*)(0x80025CEA) = ((SCREEN_WD*2)-140); //X Position of No Text for DK Arcade
    float x = SCREEN_WD_FLOAT / 2;
    *(short*)(0x80028726) = getUpper(*(int*)(&x)); //X Position of Mode Name Text
    // BARREL SCREEN
    *(short*)(0x800288C6) = SCREEN_WD / 2; //X Position of Analog Stick
    *(short*)(0x80028B1E) = SCREEN_WD - 30; //X Position of A Button
    // FILE SELECT
    x = SCREEN_WD_FLOAT / 2;
    *(short*)(0x80028DA2) = getUpper(*(int*)(&x)); //X Position of File Names
    *(short*)(0x80028EEE) = SCREEN_WD / 2; //X Position of Analog Stick
    *(short*)(0x80029026) = SCREEN_WD - 30; //X Position of A Button
    // SELECT DELETE FILE
    x = SCREEN_WD_FLOAT / 2;
    *(short*)(0x80029C02) = getUpper(*(int*)(&x)); //X Position of Erase Text
    *(short*)(0x80029D6A) = SCREEN_WD - 30; //X Position of A Button
    *(short*)(0x80029EA6) = SCREEN_WD / 2; //X Position of Bouncing Orange
    *(short*)(0x80029ED2) = SCREEN_WD / 2; //X Position of Analog Stick
    // Multiplayer Type
    x = SCREEN_WD_FLOAT / 2;
    *(short*)(0x8002A646) = getUpper(*(int*)(&x)); //X Position of Center of Battle Select Screen
    *(int*)(0x8002A83C) = 0x4600A6A1; //Fix X Position of Battle Icons
    *(short*)(0x8002ABCA) = SCREEN_WD - 30; //X Position of A Button
    *(short*)(0x8002AC32) = SCREEN_WD / 2; //X Position of Analog Stick
    // Delete Confirm
    x = SCREEN_WD_FLOAT / 2;
    *(short*)(0x8002A0CE) = getUpper(*(int*)(&x)); //X Position of Erase Game 1 Text
    *(short*)(0x8002A20E) = getUpper(*(int*)(&x)); //X Position of Are You Sure
    x = (SCREEN_WD_FLOAT / 2) - 80;
    *(short*)(0x8002A296) = getUpper(*(int*)(&x)); //X Position of No/Yes Text
    *(short*)(0x8002A312) = SCREEN_WD << 2; //X Offset of Yes Text
    *(short*)(0x8002A3AE) = SCREEN_WD - 30; //X Position of A Button
    *(short*)(0x8002A416) = SCREEN_WD / 2; //X Position of Orange
    *(short*)(0x8002A442) = SCREEN_WD / 2; //X Position of Analog Stick
    // Multiplayer Join
    x = (SCREEN_WD_FLOAT/2)+50;
    *(short*)(0x8002B756) = *(short*)(&x); //X Position of P2 Question Mark
    x = SCREEN_WD_FLOAT / 2;
    *(short*)(0x8002B7EE) = *(short*)(&x); //X Position of P3 Question Mark
    x = (SCREEN_WD_FLOAT / 2) - 50;
    *(short*)(0x8002B886) = *(short*)(&x); //X Position of P4 Question Mark
    x = SCREEN_WD_FLOAT / 2;
    *(short*)(0x8002B94A) = *(short*)(&x); //X Position of Battle Arena Text
    *(short*)(0x8002BA92) = SCREEN_WD * 2; //X Position of Game Type Text
    *(short*)(0x8002BB4A) = getHi(&pos_center);  //Load High Half of Game Mode X Position
    *(int*)(0x8002BB4C) = 0xD4240000 | getLo(&pos_center); //Load X Position of Game Mode
    *(int*)(0x8002BC18) = 0x3C010000 | getHi(&pos_center); //Load High Half of Game Type Value X Position
    *(int*)(0x8002BC1C) = 0xD4280000 | getLo(&pos_center); //Load X Position of Game Type Value
    *(short*)(0x8002BED6) = SCREEN_WD * 2; //X Position of Screen Type Text
    x = SCREEN_WD_FLOAT / 2;
    *(short*)(0x8002BF16) = *(short*)(&x);
    *(short*)(0x8002C26E) = SCREEN_WD - 30; //X Position of A Button
    *(short*)(0x8002C2CE) = SCREEN_WD / 2; //X Position of Analog Stick
    *(short*)(0x8002C2FE) = SCREEN_WD / 2; //X Position of C-Up
    *(short*)(0x8002C326) = SCREEN_WD / 2; //X Position of Start
    *(short*)(0x8002C3EA) = SCREEN_WD - 30; //X Position of A Button
    *(short*)(0x8002C43A) = SCREEN_WD / 2; //X Position of Analog Stick
    *(short*)(0x8002C472) = SCREEN_WD / 2; //X Position of C-Down
    *(short*)(0x8002C4A2) = SCREEN_WD / 2; //X Position of C-Up
    *(short*)(0x8002C4CA) = SCREEN_WD - 30; //X Position of A Button
    *(short*)(0x8002C51A) = SCREEN_WD / 2; //X Position of C-Down
    *(short*)(0x8002C54A) = SCREEN_WD / 2; //X Position of C-Down
    // Multiplayer Scores
    *(short*)(0x8002C736) = (SCREEN_WD * 2) - 570; //X Position of Player Win/Lose Status
    *(short*)(0x8002C8DE) = SCREEN_WD * 2; //X Position of Score Text
    *(short*)(0x8002CADA) = SCREEN_WD - 30; //X Position of A Button
    // Sound
    *(short*)(0x8002D5B2) = SCREEN_WD * 2; //X Position of Sound
    x = SCREEN_WD_FLOAT / 2;
    *(short*)(0x8002D646) = *(short*)(&x); //Base X Position of Sound Options
    *(short*)(0x8002D85A) = SCREEN_WD / 2; //X Position of Sound Analog Stick
    *(short*)(0x8002D88E) = SCREEN_WD / 2; //X Position of Sound Z Button
    // Options
    *(short*)(0x8002DC7A) = SCREEN_WD * 2; //X Position of Options Text
    x = SCREEN_WD_FLOAT / 2;
    *(short*)(0x8002DD0A) = *(short*)(&x); //Base X Position of Options Values
    *(short*)(0x8002DF56) = SCREEN_WD / 2; //X Position of Options Analog Stick
    *(short*)(0x8002DF8A) = SCREEN_WD / 2; //X Position of Options Z Button
    // Mystery Menu
    *(short*)(0x8002E4B2) = SCREEN_WD * 2; //X Position of Mystery Text
    *(short*)(0x8002E576) = (SCREEN_WD * 2) + 40; //X Position of Mystery Menu Number
    x = SCREEN_WD_FLOAT / 2;
    *(int*)(0x8002E59C) = 0x3C050000 | *(short*)(&x); //X Position of Cheat Name
    *(short*)(0x8002E96E) = SCREEN_WD / 2; //X Position of Mystery Menu Analog Stick
    *(short*)(0x8002E9A2) = (SCREEN_WD / 2) - 40; //X Position of Mystery Menu Fairy
    *(short*)(0x8002E9D6) = SCREEN_WD - 35; //X Position of Mystery Menu Z Button
    *(short*)(0x8002EA0A) = SCREEN_WD - 35; //X Position of Mystery Menu A Button
    // Multiplayer Kong Code
    x = SCREEN_WD_FLOAT / 2;
    *(short*)(0x8002CD72) = *(short*)(&x); //Base X Position of Players on Player Setup Screen

    float temp = SCREEN_WD_FLOAT * 2;
    *(short*)(0x800309A2) = *(short*)(&temp); //X Position of Final X Position of Buttons
    *(short*)(0x80030E0A) = (SCREEN_WD / 2) - 40; //Fix Clipping of Item Circle Entering Barrel
    *(short*)(0x80030E12) = (SCREEN_WD / 2) + 40; //Fix Clipping of Item Circle Leaving Barrel
    *(int*)(0x80030FC8) = 0x3C010000 | getHi(&pos_center_4x); //Load High Half of pos_center_4x
    *(int*)(0x80030FCC) = 0xD4200000 | getLo(&pos_center_4x); //Load pos_center_4x
    //
    temp = (SCREEN_WD_FLOAT*2)+320;
    *(short*)(0x80030F3E) = *(short*)(&temp); //Max X Position of Yes Orange
    temp = (SCREEN_WD_FLOAT*2)-320;
    *(short*)(0x80030F8A) = *(short*)(&temp); //Min X Position of No Orange

    temp = SCREEN_WD_FLOAT * 2;
    *(short*)(0x8003177A) = *(short*)(&temp); // X Position of Menu Options in Circle
    temp = SCREEN_WD_FLOAT / 2;
    *(short*)(0x80031386) = *(short*)(&temp); // X Position of File Icons
    *(short*)(0x800317EA) = *(short*)(&temp); // Base X Position of Text
    *(short*)(0x8003191A) = *(short*)(&temp); // Center X Position of Text
    *(short*)(0x80031DA6) = *(short*)(&temp); // X Position of Explosion
    *(short*)(0x80031E26) = *(short*)(&temp); // X Position of Barrel Shards

    *(short*)(0x800330E0) = ((SCREEN_WD*2)-520); //X Position of Vertex 1 of Chart Border
    *(short*)(0x800330F0) = ((SCREEN_WD*2)+520); //X Position of Vertex 2 of Chart Border
    *(short*)(0x80033100) = ((SCREEN_WD*2)+480); //X Position of Vertex 3 of Chart Border
    *(short*)(0x80033110) = ((SCREEN_WD*2)-480); //X Position of Vertex 4 of Chart Border
    *(short*)(0x80033120) = ((SCREEN_WD*2)-520); //X Position of Vertex 5 of Chart Border
    *(short*)(0x80033130) = ((SCREEN_WD*2)+520); //X Position of Vertex 6 of Chart Border
    *(short*)(0x80033140) = ((SCREEN_WD*2)+480); //X Position of Vertex 7 of Chart Border
    *(short*)(0x80033150) = ((SCREEN_WD*2)-480); //X Position of Vertex 8 of Chart Border
    *(short*)(0x80033160) = ((SCREEN_WD*2)+520); //X Position of Vertex 9 of Chart Border
    *(short*)(0x80033170) = ((SCREEN_WD*2)+520); //X Position of Vertex 10 of Chart Border
    *(short*)(0x80033180) = ((SCREEN_WD*2)+480); //X Position of Vertex 11 of Chart Border
    *(short*)(0x80033190) = ((SCREEN_WD*2)+480); //X Position of Vertex 12 of Chart Border
    *(short*)(0x800331A0) = ((SCREEN_WD*2)-520); //X Position of Vertex 13 of Chart Border
    *(short*)(0x800331B0) = ((SCREEN_WD*2)-520); //X Position of Vertex 14 of Chart Border
    *(short*)(0x800331C0) = ((SCREEN_WD*2)-480); //X Position of Vertex 15 of Chart Border
    *(short*)(0x800331D0) = ((SCREEN_WD*2)-480); //X Position of Vertex 16 of Chart Border
    *(short*)(0x800331E0) = ((SCREEN_WD*2)-320); //X Position of Vertex 17 of Chart Border
    *(short*)(0x800331F0) = ((SCREEN_WD*2)+320); //X Position of Vertex 18 of Chart Border
    *(short*)(0x80033200) = ((SCREEN_WD*2)+320); //X Position of Vertex 19 of Chart Border
    *(short*)(0x80033210) = ((SCREEN_WD*2)-320); //X Position of Vertex 20 of Chart Border
    *(float*)(0x80033894) = (SCREEN_WD_FLOAT/2); //X Position of Player 1 in Player Setup
    *(float*)(0x8003389C) = ((SCREEN_WD_FLOAT/2)+50); //X Position of Player 2 in Player Setup
    *(float*)(0x800338A4) = (SCREEN_WD_FLOAT/2); //X Position of Player 3 in Player Setup
    *(float*)(0x800338AC) = ((SCREEN_WD_FLOAT/2)-50); //X Position of Player 4 in Player Setup
}

void loadWidescreen(overlays loaded_overlay) {
    if (Rando.true_widescreen) {
        if (loaded_overlay == OVERLAY_BOOT) {
            ws_static();
            ws_staticdata();
            //ws_boot(); // Nothing here
        } else if (loaded_overlay == OVERLAY_ARCADE) {
            ws_arcade();
        } else if (loaded_overlay == OVERLAY_JETPAC) {
            ws_jetpac();
        } else if (loaded_overlay == OVERLAY_BONUS) {
            ws_minigame();
        } else if (loaded_overlay == OVERLAY_MENU) {
            ws_menu();
        }
    }
}

/*
    maybe not needed
    .org 0x805FB7F8
    li a3, (SCREEN_WD*240*2) //Size of Framebuffer for Nintendo Logo Clear

    .org 0x805FB8A4
    lui a3, hi(SCREEN_WD*240*2) //Upper Half of Clear Size
    j fix_nintendo_logo_pos //Fix Position of Nintendo Logo
    addiu a3, a3, lo(SCREEN_WD*240*2) //Lower Half of Clear Write Size

    .org 0x805FB900
    addiu v1, v1, ((SCREEN_WD-192)*2) //Line Pixel Advance for Nintendo Logo

    .org 0x80000BD4
    lui a0, hi(NOEXP_CFB1_ADDR) //Address for Framebuffer 1 Cache Invalidation

    .org 0x80000CEC
    li v1, NOEXP_CFB1_ADDR+(SCREEN_WD*240*2) //End Address of First Framebuffer Clear for Loading
    lui v0, hi(NOEXP_CFB1_ADDR) //Start Address of First Framebuffer Clear for Loading

    .org 0x80000D74
    lui a0, hi(NOEXP_CFB1_ADDR) //Address of Framebuffer for No Expansion Pak Screen Text

    .org 0x80000DB0
    addiu a1, r0, ((SCREEN_WD/2)-139) //X Position of N64 Expansion Pak Text

    .org 0x80000DC8
    addiu a1, r0, ((SCREEN_WD/2)-139) //X Position of Not Installed Text

    .org 0x80000DE0
    addiu a1, r0, ((SCREEN_WD/2)-139) //X Position of The N64 Expansion Pak Accessory Text

    .org 0x80000DF8
    addiu a1, r0, ((SCREEN_WD/2)-139) //X Position of Must be Installed in the N64  Text

    .org 0x80000E10
    addiu a1, r0, ((SCREEN_WD/2)-139) //X Position of This Game. See the N64 Expansion Text

    .org 0x80000E28
    addiu a1, r0, ((SCREEN_WD/2)-139) //X Position of Pak Instruction Booklet Text

    .org 0x80000B38
    li a0, NOEXP_CFB1_ADDR+(SCREEN_WD*240*2) //End Address of First Framebuffer for No Expansion Pak Screen

    .org 0x80000B44
    lui v0, hi(NOEXP_CFB1_ADDR) //Start Address of First Framebuffer for No Expansion Pak Screen

    .org 0x80000B74
    li a2, NOEXP_CFB1_ADDR+(SCREEN_WD*60*2) //Start Address of No Expansion Pak Image

    .org 0x80000BB4
    sh t2, (((SCREEN_WD/2)-33)*2)(v1) //Write Offset for No Expansion Pak Image

    .org 0x80000BC4
    addiu a2, a2, (SCREEN_WD*2) //Row Offset of No Expansion Pak Image
    li a1, (SCREEN_WD*240*2) //Invalidation Size for Framebuffer 1

    .org 0x80000F08
    addiu t8, r0, SCREEN_WD //Row Pitch for No Expansion Pak Screen Text
    multu t8, a2 //Calculate Row Pixel Number for No Expansion Pak Screen Text
    mflo t8 //Get Row Pixel Number for No Expansion Pak Screen Text

    *(int*)(0x8000ED10) = NOEXP_CFB1_ADDR; //Address of Framebuffer for No Expansion Pak Screen

    .org 0x80000EBC
    li a1, (SCREEN_WD*240*2) //Invalidation Size for Text Framebuffer

    .org 0x80001020
    addiu a0, a0, ((SCREEN_WD-8)*2) //Text Framebuffer Pitch

    .org 0x806FF7AC
    jal 0x806FF140 //Call Border Render Function
    addu a0, v0, r0 //Send GBI Pointer to Border Render Function
    j 0x806FFA24 //Skip Over Some Code
    addu s0, v0, r0 //Set Next GBI Address

    .org 0x8002D91C
    skip_widescreen_page:
    //Get Pointer to Options Instance
    lb a2, 0x17(a1) //Get Page of Options
    bnez a2, @@skip //Skip Over Code if Not on Options Page
    lui at, 0x8003 //Load Upper Half of Scroll Speed Address
    lw a3, 0x3F44(at) //Get Scroll Speed
    bnez a3, @@left //Assume Right Scroll if Non-Zero
    addiu t0, r0, 1 //Move to Story Skip Page
    j @@skip //Return to Game
    sb t0, 0x17(a0) //Set Options Page Number
    @@left:
    lb t0, 0x38FC(at) //Get Max Pages
    addiu t0, t0, -1 //Get Last Page
    sb t0, 0x17(a0) //Set Page Number
    @@skip:
    j 0x8002DB78 //Return to Game 
    lw a0, 0x30(sp) //Execute Replaced Instruction

    .org 0x8002DB70
    j 0x8002D91C //Jump to Code to Skip Screen Mode Page

    .org 0x8002DF00
    addiu t1, r0, 0x1 //Default Page Number of Options Menu
    sb t1, 0x17(a0) //Set Page Number of Options Menu

    .org 0x8002DF2C
    sw at, 0x10(sp) //Set Parameter 5 to func_80030894

    .org 0x8002FA28
    j fix_option_pos //Fix X Position of Options
    nop //Skip Load of Option X Position
*/

/*
    needs adjustment
    .org 0x806A2A18
    j fix_timer_pos //Fix Timer X Position

    

    .org 0x8074685C
        .area 0x1B0
        fix_nintendo_logo_pos:
        lui at, hi(((SCREEN_WD*96)+((SCREEN_WD/2)-96))*2) //Upper Half of Nintendo Logo Write Position
        j 0x805FB8B0 //Return to Game
        addiu at, at, lo(((SCREEN_WD*96)+((SCREEN_WD/2)-96))*2) //Lower Half of Nintendo Logo Write Position
        fix_timer_pos:
        andi t0, a0, 0x7FFF //Get Lower Half of Timer X Position
        slti at, t0, 0x78 //Check if Timer is on the Left
        bnez at, @@skip //Skip Realignment for Left Aligned Timers
        nop
        slti at, t0, 0xC8 //Check if TImer is on the Right
        bnez at, @@skip2 //Right Align Timer if On Right
        nop
        addiu a0, a0, (SCREEN_WD-320) //Move Timer to Right Edge
        j 0x806A2A20 //Return to Caller
        sw a0, 0x18(sp) //Execute Replaced Instruction
        @@skip2:
        addiu a0, a0, ((SCREEN_WD/2)-160) //Move Timer to Center
        @@skip:
        j 0x806A2A20 //Return to Caller
        sw a0, 0x18(sp) //Execute Replaced Instruction
        fix_option_pos:
        //Check for Options Menu Caller
        lw t6, 0x2C(sp)
        li at, 0x8002DCDC
        bne t6, at, @@skip //Skip if Caller isnt Options Menu
        nop
        bnez v1, @@skip //Check if Rendering Page 0
        nop
        addiu v1, r0, 1 //Render Page 1 Instead of Page 0
        @@skip:
        lui at, hi(pos_center) //Load High Half for Option Base Position
        j 0x8002FA30 //Return to Caller
        ldc1 f10, lo(pos_center)(at) //Load Option Base Position
        .align 8 //Align Double
        pos_center:
        .double (SCREEN_WD_FLOAT/2)
        pos_center_4x:
        .double (SCREEN_WD_FLOAT*2)
        fill_zipper_white:
        addiu a2, r0, 0 //Initialize i
        li a3, (SCREEN_WD*240) //Number of Pixels to Clear
        @@L1:
        addiu t0, r0, 0xFFFF //Pixel Clear Value
        sh t0, 0(a0) //Write Pixel
        addiu a2, a2, 1 //Increment Pixel Number
        sltu at, a2, a3 //Check for Last Pixel
        bnez at, @@L1 // Loop Until Last Pixel
        addiu a0, a0, 2 //Increment Pixel Pointer
        jr ra //Return to Game
        nop //Delay Slot
        .endarea

    .org 0x806F8534
    addiu t1, r0, (SCREEN_WD-30) //X Position of Counter 1

    .org 0x806F85C8
    addiu t2, r0, ((SCREEN_WD/2)+34) //X Position of Counter 2

    .org 0x806F8604
    addiu t3, r0, ((SCREEN_WD/2)-78) //X Position of Counter 3

    .org 0x806F8640
    addiu t8, r0, ((SCREEN_WD/2)-38) //X Position of Counter 4

    .org 0x806F868C
    addiu t2, r0, (SCREEN_WD-30) //X Position of Counter 5

    .org 0x806F86C4
    addiu t3, r0, (SCREEN_WD-30) //X Position of Counter 6

    .org 0x806F8738
    addiu t0, r0, (SCREEN_WD-30) //X Position of Counter 7

    .org 0x806F87A4
    addiu t5, r0, (SCREEN_WD-30) //X Position of Counter 8

    .org 0x806F8810
    addiu t8, r0, (SCREEN_WD-30) //X Position of Counter 9

    .org 0x806F8850
    addiu t1, r0, (SCREEN_WD-30) //X Position of Counter 10

    .org 0x806F88C8
    addiu t7, r0, (SCREEN_WD-30) //X Position of Coin Counter

    .org 0x806F8938
    addiu t2, r0, (SCREEN_WD-30) //X Position of Counter 12

    .org 0x80027A40
    li.u a1, (SCREEN_WD_FLOAT*2) //X Position of New Move Title

    .org 0x800293AC
    addiu a2, r0, (SCREEN_WD*2) //X Position of Percentage

    .org 0x800293FC
    addiu a2, r0, (SCREEN_WD*2) //X Position of Banana Count

    .org 0x80029454
    addiu a2, r0, (SCREEN_WD*2) //X Position of File Time

    .org 0x800294F0
    li.u at, ((SCREEN_WD_FLOAT/2)-75) //X Position of Clock Background

    .org 0x80029584
    li.u at, ((SCREEN_WD_FLOAT*2)-300) //X Position of Clock Hands

    .org 0x800296D0
    li.u a1, (SCREEN_WD_FLOAT/2) //X Position of Game 1 Text

    .org 0x8002980C
    addiu a2, r0, (SCREEN_WD-30) //X Position of File Confirm A Button

    .org 0x8002986C
    addiu a2, r0, ((SCREEN_WD/2)-42) //X Position of File Confirm Banana

    .org 0x800291D4
    li.u at, ((SCREEN_WD_FLOAT/2)-94) //X Position of File Icons
*/
#include "global.h"
#include "eventscript.h"
#include "eventinfo.h"
#include "constants/worldmap.h"
#include "EAstdlib.h"
#include "constants/characters.h"

const EventScr EventScrWM_Beginning[] = {
    /**
     * Disable auto-skip if START_BUTTON pressed
     */
    EVBIT_MODIFY(0x1)

    WmEvtNoFade
    WM_SPAWNLORD(WM_MU_0, CHARACTER_EIRIKA, WM_NODE_BorderMulan)
    WM_CENTERCAMONLORD(WM_MU_0)

    MUSCFAST(0x7fff)
    STAL(32)
    MUSC(0x4)

    WmEvtShowBigMap(0, 0, 0x10)
    STAL(2)

    WM_FADEOUT(0)
    WmEvtWaitFade

    /**
     * Now enable auto-skip if START_BUTTON pressed
     */
    EVBIT_MODIFY(0x0)

    /**
     * Template to show world map text
     */
    STAL(60)
    WM_SHOWTEXTWINDOW(40, 0x0001)
    WM_WAITFORTEXT
    WM_TEXTSTART
    WM_TEXT(0x08DB, 0)
    TEXTEND

    /**
     * Don't allow unit move on worldmap
     */
    SKIPWN
    ENDA
};

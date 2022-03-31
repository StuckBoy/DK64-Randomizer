# fmt: off
"""Logic file for Frantic Factory."""

from randomizer.Enums.Events import Events
from randomizer.Enums.Kongs import Kongs
from randomizer.Enums.Levels import Levels
from randomizer.Enums.Locations import Locations
from randomizer.Enums.Regions import Regions
from randomizer.Enums.Transitions import Transitions
from randomizer.LogicClasses import (Event, LocationLogic, Region,
                                     TransitionFront)

LogicRegions = {
    Regions.FranticFactoryStart: Region("Frantic Factory Start", Levels.FranticFactory, False, None, [
        LocationLogic(Locations.FactoryDonkeyMedal, lambda l: l.ColoredBananas[Levels.FranticFactory][Kongs.donkey] >= 75),
        LocationLogic(Locations.FactoryDiddyMedal, lambda l: l.ColoredBananas[Levels.FranticFactory][Kongs.diddy] >= 75),
        LocationLogic(Locations.FactoryLankyMedal, lambda l: l.ColoredBananas[Levels.FranticFactory][Kongs.lanky] >= 75),
        LocationLogic(Locations.FactoryTinyMedal, lambda l: l.ColoredBananas[Levels.FranticFactory][Kongs.tiny] >= 75),
        LocationLogic(Locations.FactoryChunkyMedal, lambda l: l.ColoredBananas[Levels.FranticFactory][Kongs.chunky] >= 75),
    ], [
        Event(Events.FactoryEntered, lambda l: True),
    ], [
        TransitionFront(Regions.FranticFactoryLobby, lambda l: True, Transitions.FactoryToIsles),
        TransitionFront(Regions.Testing, lambda l: Events.TestingGateOpened in l.Events),
        # Hatch opened already in rando if loading zones randomized
        TransitionFront(Regions.BeyondHatch, lambda l: l.settings.shuffle_loading_zones == "all" or l.Slam),
    ]),

    Regions.Testing: Region("Testing", Levels.FranticFactory, True, None, [
        LocationLogic(Locations.FactoryDonkeyNumberGame, lambda l: l.Slam and l.donkey),
        LocationLogic(Locations.FactoryDiddyBlockTower, lambda l: l.spring and l.isdiddy, True),
        LocationLogic(Locations.FactoryLankyTestingRoomBarrel, lambda l: l.balloon and l.islanky, True),
        LocationLogic(Locations.FactoryTinyDartboard, lambda l: Events.DartsPlayed in l.Events and l.tiny),
        LocationLogic(Locations.FactoryChunkyKasplat, lambda l: True),
        LocationLogic(Locations.FactoryBananaFairybyCounting, lambda l: l.camera),
        LocationLogic(Locations.FactoryBananaFairybyFunky, lambda l: l.camera and Events.DartsPlayed in l.Events),
    ], [
        Event(Events.DartsPlayed, lambda l: l.Slam and l.mini and l.feather and l.tiny),
    ], [
        TransitionFront(Regions.FranticFactoryStart, lambda l: True),
        TransitionFront(Regions.RandD, lambda l: True),
        TransitionFront(Regions.Snide, lambda l: True),
        TransitionFront(Regions.FunkyFactory, lambda l: Events.DartsPlayed in l.Events),
        TransitionFront(Regions.FactoryBossLobby, lambda l: True),
    ]),

    Regions.RandD: Region("R&D", Levels.FranticFactory, True, -1, [
        LocationLogic(Locations.FactoryDiddyRandD, lambda l: l.guitar and l.charge and l.diddy),
        LocationLogic(Locations.FactoryLankyRandD, lambda l: l.trombone and l.Slam and l.lanky),
        LocationLogic(Locations.FactoryChunkyRandD, lambda l: l.triangle and l.punch and l.hunkyChunky and l.chunky),
        LocationLogic(Locations.FactoryLankyKasplat, lambda l: True),
        LocationLogic(Locations.FactoryBattleArena, lambda l: l.grab and l.donkey),
    ], [], [
        TransitionFront(Regions.Testing, lambda l: True),
        TransitionFront(Regions.FactoryTinyRaceLobby, lambda l: l.mini and l.istiny),
        TransitionFront(Regions.ChunkyRoomPlatform, lambda l: True),
        TransitionFront(Regions.FactoryBossLobby, lambda l: True),
    ]),

    Regions.FactoryTinyRaceLobby: Region("Factory Tiny Race Lobby", Levels.FranticFactory, False, None, [
        LocationLogic(Locations.FactoryTinyCarRace, lambda l: l.istiny),
    ], [], [
        TransitionFront(Regions.RandD, lambda l: l.mini and l.istiny),
        TransitionFront(Regions.FactoryTinyRace, lambda l: l.mini and l.istiny, Transitions.FactoryRandDToRace)
    ]),

    Regions.FactoryTinyRace: Region("Factory Tiny Race", Levels.FranticFactory, False, None, [
        LocationLogic(Locations.FactoryTinyCarRace, lambda l: l.istiny),
    ], [], [
        TransitionFront(Regions.FactoryTinyRaceLobby, lambda l: True, Transitions.FactoryRaceToRandD),
    ], Transitions.FactoryRandDToRace
    ),

    Regions.ChunkyRoomPlatform: Region("Chunky Room Platform", Levels.FranticFactory, False, -1, [
        LocationLogic(Locations.FactoryDiddyChunkyRoomBarrel, lambda l: l.Slam and l.isdiddy, True),
    ], [], [
        TransitionFront(Regions.PowerHut, lambda l: True, Transitions.FactoryChunkyRoomToPower),
        TransitionFront(Regions.BeyondHatch, lambda l: True),
    ]),

    Regions.PowerHut: Region("Power Hut", Levels.FranticFactory, False, None, [
        LocationLogic(Locations.FactoryDonkeyPowerHut, lambda l: Events.MainCoreActivated in l.Events and l.isdonkey),
    ], [
        Event(Events.MainCoreActivated, lambda l: l.coconut and l.grab and l.isdonkey),
    ], [
        TransitionFront(Regions.ChunkyRoomPlatform, lambda l: True, Transitions.FactoryPowerToChunkyRoom),
    ]),

    Regions.BeyondHatch: Region("Beyond Hatch", Levels.FranticFactory, True, None, [
        LocationLogic(Locations.ChunkyKong, lambda l: l.handstand and l.Slam and l.lanky),
        LocationLogic(Locations.NintendoCoin, lambda l: Events.ArcadeLeverSpawned in l.Events and l.grab and l.donkey),
        LocationLogic(Locations.FactoryDonkeyDKArcade, lambda l: Events.ArcadeLeverSpawned in l.Events and l.grab and l.donkey),
        LocationLogic(Locations.FactoryLankyFreeChunky, lambda l: l.handstand and l.Slam and l.lanky),
        LocationLogic(Locations.FactoryTinybyArcade, lambda l: l.mini and l.tiny),
        LocationLogic(Locations.FactoryChunkyDarkRoom, lambda l: l.punch and l.Slam and l.chunky),
        LocationLogic(Locations.FactoryChunkybyArcade, lambda l: l.punch and l.ischunky, True),
        LocationLogic(Locations.FactoryDiddyKasplat, lambda l: True),
        LocationLogic(Locations.FactoryTinyKasplat, lambda l: True),
    ], [
        Event(Events.TestingGateOpened, lambda l: l.Slam),
        Event(Events.DiddyCoreSwitch, lambda l: l.Slam and l.diddy),
        Event(Events.LankyCoreSwitch, lambda l: l.Slam and l.lanky),
        Event(Events.TinyCoreSwitch, lambda l: l.Slam and l.tiny),
        Event(Events.ChunkyCoreSwitch, lambda l: l.Slam and l.chunky),
    ], [
        TransitionFront(Regions.FranticFactoryStart, lambda l: True),
        TransitionFront(Regions.InsideCore, lambda l: Events.MainCoreActivated in l.Events, Transitions.FactoryBeyondHatchToInsideCore),
        TransitionFront(Regions.MainCore, lambda l: Events.MainCoreActivated in l.Events),
        TransitionFront(Regions.CrankyFactory, lambda l: True),
        TransitionFront(Regions.CandyFactory, lambda l: True),
        TransitionFront(Regions.FactoryBossLobby, lambda l: True),
        TransitionFront(Regions.FactoryBaboonBlast, lambda l: l.blast and l.isdonkey)  # , Transitions.FactoryMainToBBlast)
    ]),

    Regions.FactoryBaboonBlast: Region("Factory Baboon Blast", Levels.FranticFactory, False, None, [], [
        Event(Events.ArcadeLeverSpawned, lambda l: l.isdonkey)
    ], [
        TransitionFront(Regions.BeyondHatch, lambda l: True)
    ]),

    Regions.InsideCore: Region("Inside Core", Levels.FranticFactory, False, -1, [
        LocationLogic(Locations.FactoryDonkeyCrusherRoom, lambda l: l.strongKong and l.isdonkey),
    ], [], [
        TransitionFront(Regions.BeyondHatch, lambda l: True, Transitions.FactoryInsideCoreToBeyondHatch),
    ]),

    Regions.MainCore: Region("Main Core", Levels.FranticFactory, True, -1, [
        LocationLogic(Locations.FactoryDiddyProductionRoom, lambda l: Events.DiddyCoreSwitch in l.Events and l.spring and l.diddy),
        LocationLogic(Locations.FactoryLankyProductionRoom, lambda l: Events.LankyCoreSwitch in l.Events and l.handstand and l.lanky),
        LocationLogic(Locations.FactoryTinyProductionRoom, lambda l: Events.TinyCoreSwitch in l.Events and l.twirl and l.istiny, True),
        LocationLogic(Locations.FactoryChunkyProductionRoom, lambda l: Events.ChunkyCoreSwitch in l.Events and l.chunky),
        LocationLogic(Locations.FactoryDonkeyKasplat, lambda l: True)
    ], [], [
        TransitionFront(Regions.BeyondHatch, lambda l: True),
    ]),

    Regions.FactoryBossLobby: Region("Factory Boss Lobby", Levels.FranticFactory, False, None, [], [], [
        TransitionFront(Regions.FactoryBoss, lambda l: l.istiny and sum(l.ColoredBananas[Levels.FranticFactory]) >= l.settings.BossBananas[Levels.FranticFactory]),
    ]),

    Regions.FactoryBoss: Region("Factory Boss", Levels.FranticFactory, False, None, [
        LocationLogic(Locations.FactoryKey, lambda l: l.twirl and l.istiny),
    ], [], []),
}
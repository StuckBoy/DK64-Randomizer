"""Location enum."""
from enum import IntEnum, auto


class Locations(IntEnum):
    """Location enum."""

    # Training Barrel locations
    IslesVinesTrainingBarrel = auto()  # ID: 1
    IslesSwimTrainingBarrel = auto()
    IslesOrangesTrainingBarrel = auto()
    IslesBarrelsTrainingBarrel = auto()

    # Pre-given move locations (36 locations) - the integer value of these matter for starting move count
    PreGiven_Location00 = auto()  # ID: 5
    PreGiven_Location01 = auto()
    PreGiven_Location02 = auto()
    PreGiven_Location03 = auto()
    PreGiven_Location04 = auto()
    PreGiven_Location05 = auto()
    PreGiven_Location06 = auto()
    PreGiven_Location07 = auto()
    PreGiven_Location08 = auto()
    PreGiven_Location09 = auto()
    PreGiven_Location10 = auto()
    PreGiven_Location11 = auto()
    PreGiven_Location12 = auto()
    PreGiven_Location13 = auto()
    PreGiven_Location14 = auto()
    PreGiven_Location15 = auto()
    PreGiven_Location16 = auto()
    PreGiven_Location17 = auto()
    PreGiven_Location18 = auto()
    PreGiven_Location19 = auto()
    PreGiven_Location20 = auto()
    PreGiven_Location21 = auto()
    PreGiven_Location22 = auto()
    PreGiven_Location23 = auto()
    PreGiven_Location24 = auto()
    PreGiven_Location25 = auto()
    PreGiven_Location26 = auto()
    PreGiven_Location27 = auto()
    PreGiven_Location28 = auto()
    PreGiven_Location29 = auto()
    PreGiven_Location30 = auto()
    PreGiven_Location31 = auto()
    PreGiven_Location32 = auto()
    PreGiven_Location33 = auto()
    PreGiven_Location34 = auto()
    PreGiven_Location35 = auto()

    # DK Isles locations
    IslesDonkeyJapesRock = auto()  # ID: 41
    IslesTinyCagedBanana = auto()
    IslesTinyInstrumentPad = auto()
    IslesLankyCagedBanana = auto()
    IslesChunkyCagedBanana = auto()
    IslesChunkyInstrumentPad = auto()
    IslesChunkyPoundtheX = auto()
    IslesBananaFairyIsland = auto()
    IslesBananaFairyCrocodisleIsle = auto()
    IslesLankyPrisonOrangsprint = auto()
    CameraAndShockwave = auto()
    RarewareBanana = auto()
    IslesLankyInstrumentPad = auto()
    IslesTinyAztecLobby = auto()
    IslesDonkeyCagedBanana = auto()
    IslesDiddySnidesLobby = auto()
    IslesDonkeyInstrumentPad = auto()
    IslesKasplatFactoryLobby = auto()
    IslesBananaFairyFactoryLobby = auto()
    IslesTinyGalleonLobby = auto()
    IslesKasplatGalleonLobby = auto()
    IslesDiddyCagedBanana = auto()
    IslesDiddySummit = auto()
    IslesBananaFairyForestLobby = auto()
    IslesDonkeyLavaBanana = auto()
    IslesDiddyInstrumentPad = auto()
    IslesKasplatCavesLobby = auto()
    IslesLankyCastleLobby = auto()
    IslesKasplatCastleLobby = auto()
    IslesChunkyHelmLobby = auto()
    IslesKasplatHelmLobby = auto()
    BananaHoard = auto()

    # Jungle Japes location
    JapesDonkeyMedal = auto()  # ID: 73
    JapesDiddyMedal = auto()
    JapesLankyMedal = auto()
    JapesTinyMedal = auto()
    JapesChunkyMedal = auto()
    DiddyKong = auto()
    JapesDonkeyFrontofCage = auto()
    JapesDonkeyFreeDiddy = auto()
    JapesDonkeyCagedBanana = auto()
    JapesDonkeyBaboonBlast = auto()
    JapesDiddyCagedBanana = auto()
    JapesDiddyMountain = auto()
    JapesLankyCagedBanana = auto()
    JapesTinyCagedBanana = auto()
    JapesChunkyBoulder = auto()
    JapesChunkyCagedBanana = auto()
    JapesDiddyTunnel = auto()
    JapesLankyGrapeGate = auto()
    JapesTinyFeatherGateBarrel = auto()
    JapesKasplatLeftTunnelNear = auto()
    JapesKasplatLeftTunnelFar = auto()
    JapesTinyStump = auto()
    JapesChunkyGiantBonusBarrel = auto()
    JapesTinyBeehive = auto()
    JapesLankySlope = auto()
    JapesKasplatNearPaintingRoom = auto()
    JapesKasplatNearLab = auto()
    JapesBananaFairyRambiCave = auto()
    JapesLankyFairyCave = auto()
    JapesBananaFairyLankyCave = auto()
    JapesDiddyMinecarts = auto()
    JapesChunkyUnderground = auto()
    JapesKasplatUnderground = auto()
    JapesKey = auto()

    # Angry Aztec
    AztecDonkeyMedal = auto()  # ID: 107
    AztecDiddyMedal = auto()
    AztecLankyMedal = auto()
    AztecTinyMedal = auto()
    AztecChunkyMedal = auto()
    AztecDonkeyFreeLlama = auto()
    AztecChunkyVases = auto()
    AztecKasplatSandyBridge = auto()
    AztecKasplatOnTinyTemple = auto()
    AztecTinyKlaptrapRoom = auto()
    AztecChunkyKlaptrapRoom = auto()
    TinyKong = auto()
    AztecDiddyFreeTiny = auto()
    AztecLankyVulture = auto()
    AztecDonkeyQuicksandCave = auto()
    AztecDiddyRamGongs = auto()
    AztecDiddyVultureRace = auto()
    AztecChunkyCagedBarrel = auto()
    AztecKasplatNearLab = auto()
    AztecDonkey5DoorTemple = auto()
    AztecDiddy5DoorTemple = auto()
    AztecLanky5DoorTemple = auto()
    AztecTiny5DoorTemple = auto()
    AztecBananaFairyTinyTemple = auto()
    AztecChunky5DoorTemple = auto()
    AztecKasplatChunky5DT = auto()
    AztecTinyBeetleRace = auto()
    LankyKong = auto()
    AztecDonkeyFreeLanky = auto()
    AztecLankyLlamaTempleBarrel = auto()
    AztecLankyMatchingGame = auto()
    AztecBananaFairyLlamaTemple = auto()
    AztecTinyLlamaTemple = auto()
    AztecKasplatLlamaTemple = auto()
    AztecKey = auto()

    # Frantic Factory locations
    FactoryDonkeyMedal = auto()  # 142
    FactoryDiddyMedal = auto()
    FactoryLankyMedal = auto()
    FactoryTinyMedal = auto()
    FactoryChunkyMedal = auto()
    FactoryDonkeyNumberGame = auto()
    FactoryDiddyBlockTower = auto()
    FactoryLankyTestingRoomBarrel = auto()
    FactoryTinyDartboard = auto()
    FactoryKasplatBlocks = auto()
    FactoryBananaFairybyCounting = auto()
    FactoryBananaFairybyFunky = auto()
    FactoryDiddyRandD = auto()
    FactoryLankyRandD = auto()
    FactoryChunkyRandD = auto()
    FactoryKasplatRandD = auto()
    FactoryTinyCarRace = auto()
    FactoryDiddyChunkyRoomBarrel = auto()
    FactoryDonkeyPowerHut = auto()
    ChunkyKong = auto()
    NintendoCoin = auto()
    FactoryDonkeyDKArcade = auto()
    FactoryLankyFreeChunky = auto()
    FactoryTinybyArcade = auto()
    FactoryChunkyDarkRoom = auto()
    FactoryChunkybyArcade = auto()
    FactoryKasplatProductionBottom = auto()
    FactoryKasplatStorage = auto()
    FactoryDonkeyCrusherRoom = auto()
    FactoryDiddyProductionRoom = auto()
    FactoryLankyProductionRoom = auto()
    FactoryTinyProductionRoom = auto()
    FactoryChunkyProductionRoom = auto()
    FactoryKasplatProductionTop = auto()
    FactoryKey = auto()

    # Gloomy Galleon locations
    GalleonDonkeyMedal = auto()  # ID: 177
    GalleonDiddyMedal = auto()
    GalleonLankyMedal = auto()
    GalleonTinyMedal = auto()
    GalleonChunkyMedal = auto()
    GalleonChunkyChest = auto()
    GalleonKasplatNearLab = auto()
    GalleonBananaFairybyCranky = auto()
    GalleonChunkyCannonGame = auto()
    GalleonKasplatCannons = auto()
    GalleonDiddyShipSwitch = auto()
    GalleonLankyEnguardeChest = auto()
    GalleonKasplatLighthouseArea = auto()
    GalleonDonkeyLighthouse = auto()
    GalleonTinyPearls = auto()
    GalleonChunkySeasick = auto()
    GalleonDonkeyFreetheSeal = auto()
    GalleonKasplatNearSub = auto()
    GalleonDonkeySealRace = auto()
    GalleonDiddyGoldTower = auto()
    GalleonLankyGoldTower = auto()
    GalleonKasplatGoldTower = auto()
    GalleonTinySubmarine = auto()
    GalleonDiddyMechafish = auto()
    GalleonLanky2DoorShip = auto()
    GalleonTiny2DoorShip = auto()
    GalleonDonkey5DoorShip = auto()
    GalleonDiddy5DoorShip = auto()
    GalleonLanky5DoorShip = auto()
    GalleonTiny5DoorShip = auto()
    GalleonBananaFairy5DoorShip = auto()
    GalleonChunky5DoorShip = auto()
    GalleonPearl0 = auto()
    GalleonPearl1 = auto()
    GalleonPearl2 = auto()
    GalleonPearl3 = auto()
    GalleonPearl4 = auto()
    GalleonKey = auto()

    # Fungi Forest locations
    ForestDonkeyMedal = auto()  # ID: 215
    ForestDiddyMedal = auto()
    ForestLankyMedal = auto()
    ForestTinyMedal = auto()
    ForestChunkyMedal = auto()
    ForestChunkyMinecarts = auto()
    ForestDiddyTopofMushroom = auto()
    ForestTinyMushroomBarrel = auto()
    ForestDonkeyBaboonBlast = auto()
    ForestKasplatLowerMushroomExterior = auto()
    ForestDonkeyMushroomCannons = auto()
    ForestKasplatInsideMushroom = auto()
    ForestKasplatUpperMushroomExterior = auto()
    ForestChunkyFacePuzzle = auto()
    ForestLankyZingers = auto()
    ForestLankyColoredMushrooms = auto()
    ForestDiddyOwlRace = auto()
    ForestLankyRabbitRace = auto()
    ForestKasplatOwlTree = auto()
    ForestTinyAnthill = auto()
    ForestDonkeyMill = auto()
    ForestDiddyCagedBanana = auto()
    ForestTinySpiderBoss = auto()
    ForestChunkyKegs = auto()
    ForestDiddyRafters = auto()
    ForestBananaFairyRafters = auto()
    ForestLankyAttic = auto()
    ForestKasplatNearBarn = auto()
    ForestDonkeyBarn = auto()
    ForestBananaFairyThornvines = auto()
    ForestTinyBeanstalk = auto()
    ForestChunkyApple = auto()
    ForestBean = auto()
    ForestKey = auto()

    # Crystal Caves locations
    CavesDonkeyMedal = auto()  # ID: 249
    CavesDiddyMedal = auto()
    CavesLankyMedal = auto()
    CavesTinyMedal = auto()
    CavesChunkyMedal = auto()
    CavesDonkeyBaboonBlast = auto()
    CavesDiddyJetpackBarrel = auto()
    CavesTinyCaveBarrel = auto()
    CavesTinyMonkeyportIgloo = auto()
    CavesChunkyGorillaGone = auto()
    CavesKasplatNearLab = auto()
    CavesKasplatNearFunky = auto()
    CavesKasplatPillar = auto()
    CavesKasplatNearCandy = auto()
    CavesLankyBeetleRace = auto()
    CavesLankyCastle = auto()
    CavesChunkyTransparentIgloo = auto()
    CavesKasplatOn5DI = auto()
    CavesDonkey5DoorIgloo = auto()
    CavesDiddy5DoorIgloo = auto()
    CavesLanky5DoorIgloo = auto()
    CavesTiny5DoorIgloo = auto()
    CavesBananaFairyIgloo = auto()
    CavesChunky5DoorIgloo = auto()
    CavesDonkeyRotatingCabin = auto()
    CavesDonkey5DoorCabin = auto()
    CavesDiddy5DoorCabinLower = auto()
    CavesDiddy5DoorCabinUpper = auto()
    CavesBananaFairyCabin = auto()
    CavesLanky1DoorCabin = auto()
    CavesTiny5DoorCabin = auto()
    CavesChunky5DoorCabin = auto()
    CavesKey = auto()

    # Creepy Castle locations
    CastleDonkeyMedal = auto()  # ID: 282
    CastleDiddyMedal = auto()
    CastleLankyMedal = auto()
    CastleTinyMedal = auto()
    CastleChunkyMedal = auto()
    CastleDiddyAboveCastle = auto()
    CastleKasplatHalfway = auto()
    CastleKasplatLowerLedge = auto()
    CastleDonkeyTree = auto()
    CastleChunkyTree = auto()
    CastleKasplatTree = auto()
    CastleBananaFairyTree = auto()
    CastleDonkeyLibrary = auto()
    CastleDiddyBallroom = auto()
    CastleBananaFairyBallroom = auto()
    CastleTinyCarRace = auto()
    CastleLankyTower = auto()
    CastleLankyGreenhouse = auto()
    CastleTinyTrashCan = auto()
    CastleChunkyShed = auto()
    CastleChunkyMuseum = auto()
    CastleKasplatCrypt = auto()
    CastleDiddyCrypt = auto()
    CastleChunkyCrypt = auto()
    CastleDonkeyMinecarts = auto()
    CastleLankyMausoleum = auto()
    CastleTinyMausoleum = auto()
    CastleTinyOverChasm = auto()
    CastleKasplatNearCandy = auto()
    CastleDonkeyDungeon = auto()
    CastleDiddyDungeon = auto()
    CastleLankyDungeon = auto()
    CastleKey = auto()

    # Hideout Helm locations
    HelmDonkey1 = auto()  # ID: 315
    HelmDonkey2 = auto()
    HelmDiddy1 = auto()
    HelmDiddy2 = auto()
    HelmLanky1 = auto()
    HelmLanky2 = auto()
    HelmTiny1 = auto()
    HelmTiny2 = auto()
    HelmChunky1 = auto()
    HelmChunky2 = auto()
    HelmDonkeyMedal = auto()
    HelmChunkyMedal = auto()
    HelmTinyMedal = auto()
    HelmLankyMedal = auto()
    HelmDiddyMedal = auto()
    HelmBananaFairy1 = auto()
    HelmBananaFairy2 = auto()
    HelmKey = auto()

    # Shop locations
    CoconutGun = auto()  # ID: 333
    PeanutGun = auto()
    GrapeGun = auto()
    FeatherGun = auto()
    PineappleGun = auto()
    AmmoBelt1 = auto()
    HomingAmmo = auto()
    AmmoBelt2 = auto()
    SniperSight = auto()
    Bongos = auto()
    Guitar = auto()
    Trombone = auto()
    Saxophone = auto()
    Triangle = auto()
    MusicUpgrade1 = auto()
    ThirdMelon = auto()
    MusicUpgrade2 = auto()
    SimianSlam = auto()
    SuperSimianSlam = auto()
    SuperDuperSimianSlam = auto()
    BaboonBlast = auto()
    StrongKong = auto()
    GorillaGrab = auto()
    ChimpyCharge = auto()
    RocketbarrelBoost = auto()
    SimianSpring = auto()
    Orangstand = auto()
    BaboonBalloon = auto()
    OrangstandSprint = auto()
    MiniMonkey = auto()
    PonyTailTwirl = auto()
    Monkeyport = auto()
    HunkyChunky = auto()
    PrimatePunch = auto()
    GorillaGone = auto()
    RarewareCoin = auto()
    # These act as placeholders for shuffled move locations. In Vanilla game there is no move here
    DonkeyGalleonPotion = auto()  # ID: 369
    DonkeyForestPotion = auto()
    DonkeyCavesPotion = auto()
    DonkeyCastlePotion = auto()
    DonkeyIslesPotion = auto()
    DiddyGalleonPotion = auto()
    DiddyForestPotion = auto()
    DiddyCavesPotion = auto()
    DiddyCastlePotion = auto()
    DiddyIslesPotion = auto()
    LankyAztecPotion = auto()
    LankyGalleonPotion = auto()
    LankyForestPotion = auto()
    LankyCastlePotion = auto()
    LankyIslesPotion = auto()
    TinyAztecPotion = auto()
    TinyGalleonPotion = auto()
    TinyForestPotion = auto()
    TinyCastlePotion = auto()
    TinyIslesPotion = auto()
    ChunkyAztecPotion = auto()
    ChunkyGalleonPotion = auto()
    ChunkyForestPotion = auto()
    ChunkyCastlePotion = auto()
    ChunkyIslesPotion = auto()
    SharedJapesPotion = auto()
    SharedAztecPotion = auto()
    SharedFactoryPotion = auto()
    SharedGalleonPotion = auto()
    SharedCavesPotion = auto()
    DonkeyAztecGun = auto()
    DonkeyFactoryGun = auto()
    DonkeyGalleonGun = auto()
    DonkeyForestGun = auto()
    DonkeyCavesGun = auto()
    DonkeyCastleGun = auto()
    DiddyAztecGun = auto()
    DiddyFactoryGun = auto()
    DiddyGalleonGun = auto()
    DiddyForestGun = auto()
    DiddyCavesGun = auto()
    DiddyCastleGun = auto()
    LankyAztecGun = auto()
    LankyFactoryGun = auto()
    LankyGalleonGun = auto()
    LankyForestGun = auto()
    LankyCavesGun = auto()
    LankyCastleGun = auto()
    TinyAztecGun = auto()
    TinyFactoryGun = auto()
    TinyGalleonGun = auto()
    TinyForestGun = auto()
    TinyCavesGun = auto()
    TinyCastleGun = auto()
    ChunkyAztecGun = auto()
    ChunkyFactoryGun = auto()
    ChunkyGalleonGun = auto()
    ChunkyForestGun = auto()
    ChunkyCavesGun = auto()
    ChunkyCastleGun = auto()
    SharedJapesGun = auto()
    SharedAztecGun = auto()
    SharedGalleonGun = auto()
    DonkeyFactoryInstrument = auto()  # ID: 432
    DonkeyGalleonInstrument = auto()
    DonkeyCavesInstrument = auto()
    DonkeyCastleInstrument = auto()
    DiddyFactoryInstrument = auto()
    DiddyGalleonInstrument = auto()
    DiddyCavesInstrument = auto()
    DiddyCastleInstrument = auto()
    LankyFactoryInstrument = auto()
    LankyGalleonInstrument = auto()
    LankyCavesInstrument = auto()
    LankyCastleInstrument = auto()
    TinyFactoryInstrument = auto()
    TinyGalleonInstrument = auto()
    TinyCavesInstrument = auto()
    TinyCastleInstrument = auto()
    ChunkyFactoryInstrument = auto()
    ChunkyGalleonInstrument = auto()
    ChunkyCavesInstrument = auto()
    ChunkyCastleInstrument = auto()
    SharedAztecInstrument = auto()
    SharedFactoryInstrument = auto()

    TurnInDKIslesDonkeyBlueprint = auto()  # ID: 454
    TurnInDKIslesDiddyBlueprint = auto()
    TurnInDKIslesLankyBlueprint = auto()
    TurnInDKIslesTinyBlueprint = auto()
    TurnInDKIslesChunkyBlueprint = auto()
    TurnInJungleJapesDonkeyBlueprint = auto()
    TurnInJungleJapesDiddyBlueprint = auto()
    TurnInJungleJapesLankyBlueprint = auto()
    TurnInJungleJapesTinyBlueprint = auto()
    TurnInJungleJapesChunkyBlueprint = auto()
    TurnInAngryAztecDonkeyBlueprint = auto()
    TurnInAngryAztecDiddyBlueprint = auto()
    TurnInAngryAztecLankyBlueprint = auto()
    TurnInAngryAztecTinyBlueprint = auto()
    TurnInAngryAztecChunkyBlueprint = auto()
    TurnInFranticFactoryDonkeyBlueprint = auto()
    TurnInFranticFactoryDiddyBlueprint = auto()
    TurnInFranticFactoryLankyBlueprint = auto()
    TurnInFranticFactoryTinyBlueprint = auto()
    TurnInFranticFactoryChunkyBlueprint = auto()
    TurnInGloomyGalleonDonkeyBlueprint = auto()
    TurnInGloomyGalleonDiddyBlueprint = auto()
    TurnInGloomyGalleonLankyBlueprint = auto()
    TurnInGloomyGalleonTinyBlueprint = auto()
    TurnInGloomyGalleonChunkyBlueprint = auto()
    TurnInFungiForestDonkeyBlueprint = auto()
    TurnInFungiForestDiddyBlueprint = auto()
    TurnInFungiForestLankyBlueprint = auto()
    TurnInFungiForestTinyBlueprint = auto()
    TurnInFungiForestChunkyBlueprint = auto()
    TurnInCrystalCavesDonkeyBlueprint = auto()
    TurnInCrystalCavesDiddyBlueprint = auto()
    TurnInCrystalCavesLankyBlueprint = auto()
    TurnInCrystalCavesTinyBlueprint = auto()
    TurnInCrystalCavesChunkyBlueprint = auto()
    TurnInCreepyCastleDonkeyBlueprint = auto()
    TurnInCreepyCastleDiddyBlueprint = auto()
    TurnInCreepyCastleLankyBlueprint = auto()
    TurnInCreepyCastleTinyBlueprint = auto()
    TurnInCreepyCastleChunkyBlueprint = auto()  # ID: 493

    # Door locations must remain grouped together in this specific order for hint door location logic
    JapesDonkeyDoor = auto()  # ID: 494
    JapesDiddyDoor = auto()
    JapesLankyDoor = auto()
    JapesTinyDoor = auto()
    JapesChunkyDoor = auto()
    AztecDonkeyDoor = auto()
    AztecDiddyDoor = auto()
    AztecLankyDoor = auto()
    AztecTinyDoor = auto()
    AztecChunkyDoor = auto()
    FactoryDonkeyDoor = auto()
    FactoryDiddyDoor = auto()
    FactoryLankyDoor = auto()
    FactoryTinyDoor = auto()
    FactoryChunkyDoor = auto()
    GalleonDonkeyDoor = auto()
    GalleonDiddyDoor = auto()
    GalleonLankyDoor = auto()
    GalleonTinyDoor = auto()
    GalleonChunkyDoor = auto()
    ForestDonkeyDoor = auto()
    ForestDiddyDoor = auto()
    ForestLankyDoor = auto()
    ForestTinyDoor = auto()
    ForestChunkyDoor = auto()
    CavesDonkeyDoor = auto()
    CavesDiddyDoor = auto()
    CavesLankyDoor = auto()
    CavesTinyDoor = auto()
    CavesChunkyDoor = auto()
    CastleDonkeyDoor = auto()
    CastleDiddyDoor = auto()
    CastleLankyDoor = auto()
    CastleTinyDoor = auto()
    CastleChunkyDoor = auto()  # ID: 528

    # Crown locations must stay grouped in this order
    JapesBattleArena = auto()  # ID: 529
    AztecBattleArena = auto()
    FactoryBattleArena = auto()
    GalleonBattleArena = auto()
    ForestBattleArena = auto()
    CavesBattleArena = auto()
    CastleBattleArena = auto()
    IslesBattleArena1 = auto()
    IslesBattleArena2 = auto()
    HelmBattleArena = auto()  # ID: 538

    # These locations are only utilized in kasplat rando and must stay grouped in this order
    JapesDonkeyKasplatRando = auto()  # ID: 539
    JapesDiddyKasplatRando = auto()
    JapesLankyKasplatRando = auto()
    JapesTinyKasplatRando = auto()
    JapesChunkyKasplatRando = auto()
    AztecDonkeyKasplatRando = auto()
    AztecDiddyKasplatRando = auto()
    AztecLankyKasplatRando = auto()
    AztecTinyKasplatRando = auto()
    AztecChunkyKasplatRando = auto()
    FactoryDonkeyKasplatRando = auto()
    FactoryDiddyKasplatRando = auto()
    FactoryLankyKasplatRando = auto()
    FactoryTinyKasplatRando = auto()
    FactoryChunkyKasplatRando = auto()
    GalleonDonkeyKasplatRando = auto()
    GalleonDiddyKasplatRando = auto()
    GalleonLankyKasplatRando = auto()
    GalleonTinyKasplatRando = auto()
    GalleonChunkyKasplatRando = auto()
    ForestDonkeyKasplatRando = auto()
    ForestDiddyKasplatRando = auto()
    ForestLankyKasplatRando = auto()
    ForestTinyKasplatRando = auto()
    ForestChunkyKasplatRando = auto()
    CavesDonkeyKasplatRando = auto()
    CavesDiddyKasplatRando = auto()
    CavesLankyKasplatRando = auto()
    CavesTinyKasplatRando = auto()
    CavesChunkyKasplatRando = auto()
    CastleDonkeyKasplatRando = auto()
    CastleDiddyKasplatRando = auto()
    CastleLankyKasplatRando = auto()
    CastleTinyKasplatRando = auto()
    CastleChunkyKasplatRando = auto()
    IslesDonkeyKasplatRando = auto()
    IslesDiddyKasplatRando = auto()
    IslesLankyKasplatRando = auto()
    IslesTinyKasplatRando = auto()
    IslesChunkyKasplatRando = auto()  # ID: 578

    # Rainbow Coin Locations used for dirt patch rando and item rando. Must remain in this order
    RainbowCoin_Location00 = auto()  # ID: 579
    RainbowCoin_Location01 = auto()
    RainbowCoin_Location02 = auto()
    RainbowCoin_Location03 = auto()
    RainbowCoin_Location04 = auto()
    RainbowCoin_Location05 = auto()
    RainbowCoin_Location06 = auto()
    RainbowCoin_Location07 = auto()
    RainbowCoin_Location08 = auto()
    RainbowCoin_Location09 = auto()
    RainbowCoin_Location10 = auto()
    RainbowCoin_Location11 = auto()
    RainbowCoin_Location12 = auto()
    RainbowCoin_Location13 = auto()
    RainbowCoin_Location14 = auto()
    RainbowCoin_Location15 = auto()  # ID: 594

    # Melon Crate Locations
    MelonCrate_Location00 = auto()
    MelonCrate_Location01 = auto()
    MelonCrate_Location02 = auto()
    MelonCrate_Location03 = auto()
    MelonCrate_Location04 = auto()
    MelonCrate_Location05 = auto()
    MelonCrate_Location06 = auto()
    MelonCrate_Location07 = auto()
    MelonCrate_Location08 = auto()
    MelonCrate_Location09 = auto()
    MelonCrate_Location10 = auto()
    MelonCrate_Location11 = auto()
    MelonCrate_Location12 = auto()

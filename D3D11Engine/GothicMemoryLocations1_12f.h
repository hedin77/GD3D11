#pragma once

/** Holds all memorylocations for the selected game */
struct GothicMemoryLocations {
    struct Functions {
        static const unsigned int Alg_Rotation3DNRad = 0x0051CAC0;
        static const int vidGetFPSRate = 0x00502030;
        static const unsigned int HandledWinMain = 0x00506AA0;
    };

    struct GlobalObjects {
        static const unsigned int zCResourceManager = 0x00914898;
        static const unsigned int zCCamera = 0x008B8EE4;
        static const unsigned int oCGame = 0x00920D8C;
        static const unsigned int zCTimer = 0x009150C0;
        static const unsigned int DInput7DeviceMouse = 0x008B2E20;
        static const unsigned int DInput7DeviceKeyboard = 0x008B2E14;
        static const unsigned int zCInput = 0x008B2798;
        static const unsigned int s_globFreePart = 0x008BA1F8;
        static const unsigned int zCOption = 0x008AE3AC;
        static const unsigned int zRenderer = 0x0090BD90;
    };

    struct zCPolyStrip {
        static const unsigned int Offset_Material = 0x34;

        static const unsigned int SetVisibleSegments = 0x005B82A0;
        static const unsigned int AlignToCamera = 0x005B8EC0;
        static const unsigned int Render = 0x005B8360;

        static const unsigned int RenderDrawPolyReturn = 0x005B8850;
    };

    struct zCQuadMark {
        static const unsigned int Constructor = 0x005C8490;
        static const unsigned int Destructor = 0x005C86E0;
        static const unsigned int CreateQuadMark = 0x005C9DB0;
        static const unsigned int Offset_QuadMesh = 0x34;
        static const unsigned int Offset_Material = 0x3C;
        static const unsigned int Offset_ConnectedVob = 0x38;
        static const unsigned int Offset_DontRepositionConnectedVob = 0x48;
    };

    struct zCRndD3D {
        static const unsigned int VidSetScreenMode = 0x0075C500;
        static const unsigned int DrawLineZ = 0x00752C90;
        static const unsigned int DrawLine = 0x00752A70;
        static const unsigned int DrawPoly = 0x00750960;
        static const unsigned int DrawPolySimple = 0x007501C0;

        static const unsigned int Offset_RenderState = 0x34;
    };

    struct zCOption {
        static const unsigned int ReadInt = 0x004645B0;
        static const unsigned int ReadBool = 0x00464330;
        static const unsigned int ReadDWORD = 0x004646C0;
        static const unsigned int Offset_CommandLine = 0x284;
    };

    struct zFILE {
        static const unsigned int Open = 0x00444850;
    };

    struct zCMesh {
        static const unsigned int Offset_Polygons = 0x44;
        static const unsigned int Offset_NumPolygons = 0x34;
    };

    struct zCMeshSoftSkin {
        static const unsigned int Offset_VertWeightStream = 0x0F8;
    };

    struct zCSkyController_Outdoor {
        static const unsigned int OBJ_ActivezCSkyController = 0x0099AC8C;

        static const unsigned int Offset_MasterTime = 0x6C;
        static const unsigned int Offset_MasterState = 0x74;

        static const unsigned int GetUnderwaterFX = 0x5D8600;
        static const unsigned int Offset_OverrideColor = 0x558;
        static const unsigned int Offset_OverrideFlag = 0x564;

        static const unsigned int SetCameraLocationHint = 0x005DA380;

        static const unsigned int LOC_SunVisibleStart = 0x5DEC69;
        static const unsigned int LOC_SunVisibleEnd = 0x5DEC75;

        static const unsigned int LOC_ProcessRainFXNOPStart = 0x005DEE97;
        static const unsigned int LOC_ProcessRainFXNOPEnd = 0x005DEF96;

        static const unsigned int ProcessRainFX = 0x005DECA0;
        static const unsigned int Offset_OutdoorRainFXWeight = 0x66C;
    };

    struct zCSkyController {
        static const unsigned int VTBL_RenderSkyPre = 20;
        static const unsigned int VTBL_RenderSkyPost = 21;
    };

    struct zCParticleEmitter {
        static const unsigned int Offset_VisIsQuadPoly = 0x190;
        static const unsigned int Offset_VisTexture = 0x2DC;
        static const unsigned int Offset_VisAlignment = 0x2E4;

        static const unsigned int Offset_VisAlphaBlendFunc = 0x308;
    };

    struct zCStaticPfxList {
        static const unsigned int TouchPFX = 0x005A8B30;
    };

    struct zERROR {
        // Start/End for problematic SendMessage-Broadcast which causes the game to conflict with other applications
        //static const unsigned int BroadcastStart = 0x0044CB2D;
        //static const unsigned int BroadcastEnd = 0x0044CB3C;
    };

    struct zCCamera {
        static const unsigned int GetTransform = 0x0054D440;
        static const unsigned int SetTransform = 0x0054D2E0;
        static const unsigned int UpdateViewport = 0x0054D830;
        static const unsigned int Activate = 0x0054D4A0;
        static const unsigned int SetFarPlane = 0x0054DD00;
        static const unsigned int BBox3DInFrustum = 0x0054DEA0;
        static const unsigned int SetFOV = 0x0054D700;
        static const unsigned int GetFOV_f2 = 0x0054D690;

        static const unsigned int Offset_FarPlane = 2272;
        static const unsigned int Offset_NearPlane = 2276;
    };

    struct zCVob {
        static const unsigned int Offset_WorldMatrixPtr = 0x3C;
        static const unsigned int GetVisual = 0x0060A0A0;
        static const unsigned int SetVisual = 0x005F63E0;
        static const unsigned int GetPositionWorld = 0x0060EB60;
        static const unsigned int Offset_GroundPoly = 0x0AC;
        static const unsigned int DoFrameActivity = 0x005F6BE0;
        static const unsigned int GetBBoxLocal = 0x0060E470;
        static const unsigned int Offset_HomeWorld = 0x0A8;

        static const unsigned int Offset_Flags = 0xE4;
        static const unsigned int MASK_ShowVisual = 0x1;
        static const unsigned int Offset_CameraAlignment = 0x110;
        static const unsigned int SHIFTLR_CameraAlignment = 0x1E;

        static const unsigned int Destructor = 0x005F2490;

        static const unsigned int Offset_WorldPosX = 0x48;
        static const unsigned int Offset_WorldPosY = 0x58;
        static const unsigned int Offset_WorldPosZ = 0x68;

        static const unsigned int Offset_SleepingMode = 0xEC;
        static const unsigned int MASK_SkeepingMode = 3;

        static const unsigned int EndMovement = 0x00611840;
    };

    struct zCInput {
        static const unsigned int GetDeviceEnabled = 0x004D8720;
        static const unsigned int SetDeviceEnabled = 0x004D86E0;
    };

    struct zCVisual {
        static const unsigned int VTBL_GetFileExtension = 17;
        static const unsigned int Destructor = 0x005F9870;
    };

    struct zCBspTree {
        static const unsigned int AddVob = 0x005344B0;
        static const unsigned int LoadBIN = 0x0053B550;
        static const unsigned int Offset_NumPolys = 0x24;
        static const unsigned int Offset_PolyArray = 0x10;
        static const unsigned int Offset_RootNode = 0x8;
        static const unsigned int Offset_WorldMesh = 0xC;
        static const unsigned int Offset_LeafList = 0x18;
        static const unsigned int Offset_NumLeafes = 0x20;
        static const unsigned int Offset_ArrPolygon = 0x4C;
        static const unsigned int Offset_BspTreeMode = 0x58;
        static const unsigned int Render = 0x005335A0;
    };

    struct zCBspBase {
        static const unsigned int CollectPolysInBBox3D = 0x00535F20;
        static const unsigned int CheckRayAgainstPolys = 0x00534F30;
        static const unsigned int CheckRayAgainstPolysCache = 0x00535270;
        static const unsigned int CheckRayAgainstPolysNearestHit = 0x00535090;

    };

    struct zCPolygon {
        static const unsigned int Offset_VerticesArray = 0x00;
        static const unsigned int Offset_FeaturesArray = 0x2C;
        static const unsigned int Offset_NumPolyVertices = 0x30;
        static const unsigned int Offset_PolyFlags = 0x31;
        static const unsigned int Offset_Material = 0x18;
        static const unsigned int Offset_Lightmap = 0x1C;

        static const unsigned int AllocVerts = 0x005B59A0;
        static const unsigned int CalcNormal = 0x005B24D0;

        static const unsigned int Constructor = 0x005B19F0;
        static const unsigned int Destructor = 0x005B1A20;

        static const unsigned int Size = 0x38;
    };

    struct zCThread {
        static const unsigned int SuspendThread = 0x005ECF70;
        static const unsigned int Offset_SuspendCount = 0x0C;
    };

    struct zCBspLeaf {
        static const unsigned int Size = 0x5C;
    };

    struct zSTRING {
        static const unsigned int ToChar = 0x00465C00;
        static const unsigned int ConstructorCharPtr = 0x004010C0;
    };

    struct zCModelPrototype {
        static const unsigned int Offset_NodeList = 0x74;
    };

    struct zCModelTexAniState {
        static const unsigned int UpdateTexList = 0x005759B0;
    };

    struct zCMaterial {
        static const unsigned int Offset_Color = 0x38;
        static const unsigned int Offset_Texture = 0x34;
        static const unsigned int Offset_AlphaFunc = 0x70;
        static const unsigned int Offset_MatGroup = 0x40;
        static const unsigned int Offset_TexAniCtrl = 0x4C;

        static const unsigned int InitValues = 0x00565790;
        static const unsigned int Constructor = 0x00565370;
        static const unsigned int Destructor = 0x005655E0;
        static const unsigned int GetAniTexture = 0x00751320;

    };

    struct zCObject {
        static const unsigned int GetObjectName = 0x005A54F0;
    };

    struct zCTexture {
        static const unsigned int zCTex_D3DInsertTexture = 0x00759E90;
        static const unsigned int LoadResourceData = 0x005E9020;
        static const unsigned int Offset_CacheState = 0x4C;
        static const unsigned int Mask_CacheState = 3;

        static const unsigned int Offset_Flags = 0x88;
        static const unsigned int Mask_FlagHasAlpha = 0x1;
        static const unsigned int Mask_FlagIsAnimated = 0x2;

        static const unsigned int zCResourceTouchTimeStamp = 0x005D2C40;
        static const unsigned int zCResourceTouchTimeStampLocal = 0x005D2CD0;

        static const unsigned int Offset_Surface = 0xD4;

        static const unsigned int PrecacheTexAniFrames = 0x005E7370;
    };

    struct zCBinkPlayer {
        static const unsigned int GetPixelFormat = 0x00441AF0;
        static const unsigned int OpenVideo = 0x0043F3D0;
        static const unsigned int Offset_VideoHandle = 0x30;
    };

    struct oCSpawnManager {
        static const unsigned int SpawnNpc = 0x00707230;
        static const unsigned int CheckInsertNpc = 0x00706880;
        static const unsigned int CheckRemoveNpc = 0x007075C0;
    };

    struct zCDecal {
        static const unsigned int Offset_DecalSettings = 0x34;
    };

    struct zCResourceManager {
        static const unsigned int CacheIn = 0x005D3450;
    };

    struct zCProgMeshProto {
        static const unsigned int Offset_PositionList = 0x34;
        static const unsigned int Offset_NormalsList = 0x38;
        static const unsigned int Offset_Submeshes = 0xA4;
        static const unsigned int Offset_NumSubmeshes = 0xA8;
    };

    struct zCWorld {
        static const unsigned int Render = 0x00614D70;
        static const unsigned int LoadWorld = 0x00619EC0;
        static const unsigned int VobRemovedFromWorld = 0x006174A0;
        static const unsigned int VobAddedToWorld = 0x00617340;
        static const unsigned int Offset_GlobalVobTree = 0x24;
        static const unsigned int Call_Render_zCBspTreeRender = 0x00614E45;
        static const unsigned int Offset_SkyControllerOutdoor = 0x0D0;
        static const unsigned int DisposeVobs = 0x00616570;
        static const unsigned int Offset_BspTree = 0x198;
        static const unsigned int RemoveVob = 0x00617690;
    };

    struct oCWorld {
        static const unsigned int InsertVobInWorld = 0x0070EC40;
        static const unsigned int EnableVob = 0x0070EC50;
        static const unsigned int DisableVob = 0x0070ED90;
        static const unsigned int RemoveFromLists = 0x0070F2B0;
        static const unsigned int RemoveVob = 0x0070E9D0;
    };

    struct zCBspNode {
        /*static const unsigned int RenderIndoor = 0x0052A3E0;
        static const unsigned int RenderOutdoor = 0x0052A7B0;
        static const unsigned int REPL_RenderIndoorEnd = 0x0052A47D;

        static const unsigned int REPL_RenderOutdoorStart = 0x0052A7B0;
        static const unsigned int REPL_RenderOutdoorEnd = 0x0052A9BA;
        static const unsigned int SIZE_RenderOutdoor = 0x252;*/

    };

    struct oCNPC {
        static const unsigned int ResetPos = 0x0078EA60;
        static const unsigned int Enable = 0x006D4820;
        static const unsigned int Disable = 0x006D4510;
        static const unsigned int InitModel = 0x006C69B0;
        static const unsigned int IsAPlayer = 0x006D0D70;
        static const unsigned int GetName = 0x006BD8F0;
        static const unsigned int HasFlag = 0x006BEB10;
    };

    struct oCGame {
        static const unsigned int EnterWorld = 0x00665950;
        static const unsigned int TestKeys = 0x0068C290;
        static const unsigned int Var_Player = 0x00923134;
        static const unsigned int Offset_GameView = 0x30;
        static const unsigned int Offset_SingleStep = 0x118;
    };

    struct zCViewDraw {
        static const unsigned int GetScreen = 0x00795F10;
        static const unsigned int SetVirtualSize = 0x00797840;
    };

    struct zCView {
        static const unsigned int SetMode = 0x0073C950;
        static const unsigned int REPL_SetMode_ModechangeStart = 0x0073C979;
        static const unsigned int REPL_SetMode_ModechangeEnd = 0x0073C988;
        static const unsigned int PrintTimed = 0x007385A0;

        static const unsigned int PrintChars = 0x0073A580;
        static const unsigned int CreateText = 0x0073AD20;
    };

    struct zCVobLight {
        static const unsigned int Offset_LightColor = 0x120;
        static const unsigned int Offset_Range = 0x124;
        static const unsigned int Offset_LightInfo = 0x144;
        static const unsigned int Mask_LightEnabled = 0x20;
        static const unsigned int Offset_IsStatic = 0x164;
        static const unsigned int DoAnimation = 0x005FB340;
    };

    struct zCMorphMesh {
        static const unsigned int Offset_MorphMesh = 0x38;
        static const unsigned int Offset_TexAniState = 0x40;
        static const unsigned int AdvanceAnis = 0x005A1E90;
        static const unsigned int CalcVertexPositions = 0x005A19E0;

    };

    struct zCParticleFX {
        static const unsigned int Offset_FirstParticle = 0x34;
        static const unsigned int Offset_TimeScale = 0x8C;
        static const unsigned int Offset_LocalFrameTimeF = 0x90;
        static const unsigned int Offset_PrivateTotalTime = 0x84;
        static const unsigned int Offset_LastTimeRendered = 0x88;
        static const unsigned int Offset_Emitters = 0x54;
        static const unsigned int Offset_ConnectedVob = 0x70;

        static const unsigned int OBJ_s_pfxList = 0x008BA1E0;
        static const unsigned int OBJ_s_partMeshQuad = 0x008BA200;
        static const unsigned int CheckDependentEmitter = 0x005ACC20;
        static const unsigned int UpdateParticle = 0x005AABF0;

        static const unsigned int CreateParticlesUpdateDependencies = 0x005AA930;
        static const unsigned int SetVisualUsedBy = 0x005A9390;
        static const unsigned int Destructor = 0x005A88D0;
        static const unsigned int UpdateParticleFX = 0x005AA850;
        static const unsigned int GetVisualDied = 0x005A8880;
    };

    struct zCModel {
        static const unsigned int RenderNodeList = 0x00577E70;
        static const unsigned int UpdateAttachedVobs = 0x0057F330;
        static const unsigned int Offset_ModelProtoList = 0x58;
        static const unsigned int Offset_NodeList = 0x64;
        static const unsigned int Offset_MeshSoftSkinList = 0x70;
        static const unsigned int Offset_MeshLibList = 0xB0;
        static const unsigned int Offset_AttachedVobList = 0x8C;
        static const unsigned int Offset_Flags = 0x1CC;
        static const unsigned int Offset_ModelFatness = 0x118;
        static const unsigned int Offset_ModelScale = 0x11C;
        static const unsigned int Offset_DistanceModelToCamera = 0x114;
        static const unsigned int Offset_NumActiveAnis = 0x34;
        static const unsigned int GetVisualName = 0x0057C770;
    };

    class VobTypes // vftables
    {
    public:
        static const unsigned int
            Npc = 0x820EF4,
            Mob = 0x820CB0,
            Item = 0x82001C,
            Mover = 0x81EF04,
            MobFire = 0x820984,
            VobLight = 0x81E4CC;
    protected:
        VobTypes() {}
    };
};

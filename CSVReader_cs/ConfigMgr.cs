
using UnityEngine;
using System.Collections;

public class ConfigMgr 
{
    public static ConfigMgr  Instance   {get {return instance;}}
    private static ConfigMgr instance;

		public TreasuresRefreshConfigTable      TreasuresRefresh;
		public CardStrengthenConfigTable      CardStrengthen;
		public CardEvolutionConfigTable      CardEvolution;
		public CardCardConfigTable      CardCard;
		public ConversationConversationConfigTable      ConversationConversation;
		public RoleSystemConfigTable      RoleSystem;
		public RoleSelectConfigTable      RoleSelect;
		public RoleRoleConfigTable      RoleRole;
		public CapsulePriceConfigTable      CapsulePrice;
		public EquipSuitConfigTable      EquipSuit;
		public EquipPositionConfigTable      EquipPosition;
		public EquipEvolutionConfigTable      EquipEvolution;
		public EquipQualityratioConfigTable      EquipQualityratio;
		public EquipEquipConfigTable      EquipEquip;
		public EquipStrengthenConfigTable      EquipStrengthen;
		public ThiefInstanceConfigTable      ThiefInstance;
		public ThiefThiefConfigTable      ThiefThief;
		public ItemSortConfigTable      ItemSort;
		public ItemFuseConfigTable      ItemFuse;
		public ItemPvpshopConfigTable      ItemPvpshop;
		public ItemItemConfigTable      ItemItem;
		public ItemShopConfigTable      ItemShop;
		public ItemFragmentConfigTable      ItemFragment;
		public ActivityInstanceConfigTable      ActivityInstance;
		public ActivityMcardConfigTable      ActivityMcard;
		public MsgErrcodeConfigTable      MsgErrcode;
		public MsgMsgConfigTable      MsgMsg;
		public MsgFormatConfigTable      MsgFormat;
		public MsgDescConfigTable      MsgDesc;
		public VipSigninConfigTable      VipSignin;
		public VipVipConfigTable      VipVip;
		public MonsterCategoryConfigTable      MonsterCategory;
		public MonsterMonsterConfigTable      MonsterMonster;
		public MonsterIllustrateConfigTable      MonsterIllustrate;
		public MissionMissionConfigTable      MissionMission;
		public TutorialStepConfigTable      TutorialStep;
		public TutorialGuideConfigTable      TutorialGuide;
		public SigninSigninConfigTable      SigninSignin;
		public ChapterStageConfigTable      ChapterStage;
		public ChapterInstanceConfigTable      ChapterInstance;
		public ChapterAwardConfigTable      ChapterAward;
		public ChapterChapterConfigTable      ChapterChapter;
		public ChapterSearchConfigTable      ChapterSearch;
		public GiftGiftConfigTable      GiftGift;
		public SkillBuffConfigTable      SkillBuff;
		public SkillSkillConfigTable      SkillSkill;
		public PvpRankawardConfigTable      PvpRankaward;
		public PvpLuckConfigTable      PvpLuck;
		public PvpIntegralawardConfigTable      PvpIntegralaward;
		public PayPayConfigTable      PayPay;
		public GroupTestConfigTable      GroupTest;
		public GroupProductConfigTable      GroupProduct;
		public MapMapConfigTable      MapMap;


    public ConfigMgr () 
    {
        if (instance != null)
        {
            Debug.LogError("Multiple configMgr instances");
        }
        else
        {
            TreasuresRefresh = new TreasuresRefreshConfigTable();
            TreasuresRefresh.Load();
            CardStrengthen = new CardStrengthenConfigTable();
            CardStrengthen.Load();
            CardEvolution = new CardEvolutionConfigTable();
            CardEvolution.Load();
            CardCard = new CardCardConfigTable();
            CardCard.Load();
            ConversationConversation = new ConversationConversationConfigTable();
            ConversationConversation.Load();
            RoleSystem = new RoleSystemConfigTable();
            RoleSystem.Load();
            RoleSelect = new RoleSelectConfigTable();
            RoleSelect.Load();
            RoleRole = new RoleRoleConfigTable();
            RoleRole.Load();
            CapsulePrice = new CapsulePriceConfigTable();
            CapsulePrice.Load();
            EquipSuit = new EquipSuitConfigTable();
            EquipSuit.Load();
            EquipPosition = new EquipPositionConfigTable();
            EquipPosition.Load();
            EquipEvolution = new EquipEvolutionConfigTable();
            EquipEvolution.Load();
            EquipQualityratio = new EquipQualityratioConfigTable();
            EquipQualityratio.Load();
            EquipEquip = new EquipEquipConfigTable();
            EquipEquip.Load();
            EquipStrengthen = new EquipStrengthenConfigTable();
            EquipStrengthen.Load();
            ThiefInstance = new ThiefInstanceConfigTable();
            ThiefInstance.Load();
            ThiefThief = new ThiefThiefConfigTable();
            ThiefThief.Load();
            ItemSort = new ItemSortConfigTable();
            ItemSort.Load();
            ItemFuse = new ItemFuseConfigTable();
            ItemFuse.Load();
            ItemPvpshop = new ItemPvpshopConfigTable();
            ItemPvpshop.Load();
            ItemItem = new ItemItemConfigTable();
            ItemItem.Load();
            ItemShop = new ItemShopConfigTable();
            ItemShop.Load();
            ItemFragment = new ItemFragmentConfigTable();
            ItemFragment.Load();
            ActivityInstance = new ActivityInstanceConfigTable();
            ActivityInstance.Load();
            ActivityMcard = new ActivityMcardConfigTable();
            ActivityMcard.Load();
            MsgErrcode = new MsgErrcodeConfigTable();
            MsgErrcode.Load();
            MsgMsg = new MsgMsgConfigTable();
            MsgMsg.Load();
            MsgFormat = new MsgFormatConfigTable();
            MsgFormat.Load();
            MsgDesc = new MsgDescConfigTable();
            MsgDesc.Load();
            VipSignin = new VipSigninConfigTable();
            VipSignin.Load();
            VipVip = new VipVipConfigTable();
            VipVip.Load();
            MonsterCategory = new MonsterCategoryConfigTable();
            MonsterCategory.Load();
            MonsterMonster = new MonsterMonsterConfigTable();
            MonsterMonster.Load();
            MonsterIllustrate = new MonsterIllustrateConfigTable();
            MonsterIllustrate.Load();
            MissionMission = new MissionMissionConfigTable();
            MissionMission.Load();
            TutorialStep = new TutorialStepConfigTable();
            TutorialStep.Load();
            TutorialGuide = new TutorialGuideConfigTable();
            TutorialGuide.Load();
            SigninSignin = new SigninSigninConfigTable();
            SigninSignin.Load();
            ChapterStage = new ChapterStageConfigTable();
            ChapterStage.Load();
            ChapterInstance = new ChapterInstanceConfigTable();
            ChapterInstance.Load();
            ChapterAward = new ChapterAwardConfigTable();
            ChapterAward.Load();
            ChapterChapter = new ChapterChapterConfigTable();
            ChapterChapter.Load();
            ChapterSearch = new ChapterSearchConfigTable();
            ChapterSearch.Load();
            GiftGift = new GiftGiftConfigTable();
            GiftGift.Load();
            SkillBuff = new SkillBuffConfigTable();
            SkillBuff.Load();
            SkillSkill = new SkillSkillConfigTable();
            SkillSkill.Load();
            PvpRankaward = new PvpRankawardConfigTable();
            PvpRankaward.Load();
            PvpLuck = new PvpLuckConfigTable();
            PvpLuck.Load();
            PvpIntegralaward = new PvpIntegralawardConfigTable();
            PvpIntegralaward.Load();
            PayPay = new PayPayConfigTable();
            PayPay.Load();
            GroupTest = new GroupTestConfigTable();
            GroupTest.Load();
            GroupProduct = new GroupProductConfigTable();
            GroupProduct.Load();
            MapMap = new MapMapConfigTable();
            MapMap.Load();

            instance = this;
        }
    }
}

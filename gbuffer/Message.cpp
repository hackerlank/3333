
#include "MessageSerializer.h"
#include "platcommon/pmd.pb.h"
#include "platcommon/nullcommand.pb.h"
#include "platcommon/chatcommand.pb.h"
#include "platcommon/forwardcommand.pb.h"
#include "platcommon/logincommand.pb.h"
#include "platcommon/config.pb.h"
#include "platcommon/monitorpmd.pb.h"
#include "platcommon/sdkcommand.pb.h"
#include "platcommon/gmcommand.pb.h"

#include "servercommon/super.pb.h"
#include "servercommon/smd.pb.h"
#include "servercommon/gate.pb.h"
#include "servercommon/login.pb.h"
#include "servercommon/name.pb.h"
#include "servercommon/monitor.pb.h"
#include "servercommon/sdk.pb.h"
#include "servercommon/gm.pb.h"
#include "servercommon/build.pb.h"

#include "common/server/SessionCommand.pb.h"
#include "common/server/RelationCommand.pb.h"
#include "common/server/gamesmd.pb.h"
#include "common/server/SceneCommand.pb.h"
#include "common/server/RecordCommand.pb.h"
#include "common/server/ShareCommand.pb.h"

#include "common/user/AuctionUserCmd.pb.h"
#include "common/user/ChatUserCmd.pb.h"
#include "common/user/Cmd.pb.h"
#include "common/user/ControlUserCmd.pb.h"
#include "common/user/CountryUserCmd.pb.h"
#include "common/user/CorpsUserCmd.pb.h"
#include "common/user/CopyUserCmd.pb.h"
#include "common/user/AirShipUserCmd.pb.h"
#include "common/user/AwardUserCmd.pb.h"
#include "common/user/BuyCommissionUserCmd.pb.h"
#include "common/user/InviteComposeUserCmd.pb.h"
#include "common/user/RoleUserCmd.pb.h"
#include "common/user/LotteryUserCmd.pb.h"
#include "common/user/DataUserCmd.pb.h"
#include "common/user/GoldUserCmd.pb.h"
#include "common/user/LogonUserCmd.pb.h"
#include "common/user/MagicUserCmd.pb.h"
#include "common/user/MailUserCmd.pb.h"
#include "common/user/MapScreenUserCmd.pb.h"
#include "common/user/MoveUserCmd.pb.h"
#include "common/user/PropertyUserCmd.pb.h"
#include "common/user/QuestUserCmd.pb.h"
#include "common/user/ReliveUserCmd.pb.h"
#include "common/user/RequestUserCmd.pb.h"
#include "common/user/ArmyEquipUserCmd.pb.h"
#include "common/user/ScriptUserCmd.pb.h"
#include "common/user/SelectUserCmd.pb.h"
#include "common/user/SkillUserCmd.pb.h"
#include "common/user/SysSettingUserCmd.pb.h"
#include "common/user/TimerUserCmd.pb.h"
#include "common/user/RelationUserCmd.pb.h"
#include "common/user/EquipUserCmd.pb.h"
#include "common/user/TradeUserCmd.pb.h"
#include "common/user/DemonUserCmd.pb.h"
#include "common/user/MsgBoxUserCmd.pb.h"

void initParamDescriptor()
{
	Pmd::Null_Param_descriptor();
	Pmd::Monitor_Param_descriptor();
	Pmd::Login_Param_descriptor();
	Pmd::Forward_Param_descriptor();
	Pmd::Sdk_Param_descriptor();
	Pmd::Gm_Param_descriptor();
	Pmd::Chat_Param_descriptor();

	Smd::Gate_Param_descriptor();
	Smd::Login_Param_descriptor();
	Smd::NameS_Param_descriptor();
	Smd::Monitor_Param_descriptor();
	Smd::Gm_Param_descriptor();
	Smd::Build_Param_descriptor();


	GameSmd::UserLoginShareSmd_Param_descriptor();

	GameSmd::LoginSceneSmd_Param_descriptor();
	GameSmd::ForwardSceneSmd_Param_descriptor();
	GameSmd::MapSceneSmd_Param_descriptor();

	Smd::StartupSuperSmd_Param_descriptor();
	Smd::ForwardSuperSmd_Param_descriptor();
	Smd::LoginSuperSmd_Param_descriptor();

	GameSmd::LoginSessionSmd_Param_descriptor();
	GameSmd::SceneSessionSmd_Param_descriptor();
	GameSmd::ForwardSessionSmd_Param_descriptor();
	GameSmd::SelectSessionSmd_Param_descriptor();
	GameSmd::RelationSessionSmd_Param_descriptor();

	GameCmd::AuctionUserCmd_Param_descriptor();
	GameCmd::ChatUserCmd_Param_descriptor();
	//GameCmd::Cmd_Param_descriptor();
	GameCmd::ControlUserCmd_Param_descriptor();
	GameCmd::CountryUserCmd_Param_descriptor();
	GameCmd::CorpsUserCmd_Param_descriptor();
	GameCmd::CopyUserCmd_Param_descriptor();
	GameCmd::AwardUserCmd_Param_descriptor();
	GameCmd::AirShipUserCmd_Param_descriptor();
	GameCmd::BuyCommissionUserCmd_Param_descriptor();
	GameCmd::InviteComposeUserCmd_Param_descriptor();
	GameCmd::RoleUserCmd_Param_descriptor();
	GameCmd::LotteryUserCmd_Param_descriptor();
	GameCmd::DataUserCmd_Param_descriptor();
	GameCmd::GoldUserCmd_Param_descriptor();
	GameCmd::LogonUserCmd_Param_descriptor();
	GameCmd::MagicUserCmd_Param_descriptor();
	GameCmd::MailUserCmd_Param_descriptor();
	GameCmd::MapScreenUserCmd_Param_descriptor();
	GameCmd::MoveUserCmd_Param_descriptor();
	GameCmd::PropertyUserCmd_Param_descriptor();
	GameCmd::QuestUserCmd_Param_descriptor();
	GameCmd::ReliveUserCmd_Param_descriptor();
	GameCmd::RequestUserCmd_Param_descriptor();
	GameCmd::ArmyEquipUserCmd_Param_descriptor();
	GameCmd::ScriptUserCmd_Param_descriptor();
	GameCmd::SelectUserCmd_Param_descriptor();
	GameCmd::SkillUserCmd_Param_descriptor();
	GameCmd::SysSettingUserCmd_Param_descriptor();
	GameCmd::TimerUserCmd_Param_descriptor();
	GameCmd::RelationUserCmd_Param_descriptor();
	GameCmd::EquipUserCmd_Param_descriptor();
	GameCmd::TradeUserCmd_Param_descriptor();
	GameCmd::DemonUserCmd_Param_descriptor();
	GameCmd::MsgBoxUserCmd_Param_descriptor();
}

namespace gbuffer{
	bool RegisterMessage(MessageSerializer* serializer)
	{
		initParamDescriptor();
		if(serializer->Register(Pmd::PlatCommand_descriptor(),"Pmd") == false)
			return false;
		if(serializer->Register(Smd::ServerCommand_descriptor(),"Smd") == false)
			return false;
		if(serializer->Register(GameSmd::ServerCommand_descriptor(),"GameSmd") == false)
			return false;
		if(serializer->Register(GameCmd::ClientCommand_descriptor(),"GameCmd") == false)
			return false;
		return true;
	}
}

#include "group_data.h"

//https://x.com/tozamasan/status/2047246489844687195参照
static const struct Member morning_musume_members[] = {
  {"nonaka_miki", 0x582C83},
  {"oda_sakura", 0xA05EB5},
  {"okamura_homare", 0xFDDA24},
  {"yamazaki_mei", 0x005EB8},
  {"sakurai_rio", 0xD3BBA8},
  {"inoue_haruka", 0x00C7B1},
  {"yumigeta_ako", 0xDB0025},
  {"sugihara_meisa", 0xB9D9EB},
  {"yasuda_miyu", 0x00B140},
  {"suzuki_moa", 0xDA1884},
  {"ishikawa_hanano", 0xFC4C02},
};

static const struct Member angerme_members[] = {
  {"ise_layla", 0xFC4C02},
  {"tamenaga_shion", 0xF57EB6},
  {"hashisako_rin", 0xE70033},
  {"kawana_rin", 0x00B140},
  {"matsumoto_wakana", 0xFFFFFF},
  {"hirayama_yuki", 0xD0DF00},
  {"shimoitani_yukiho", 0xDA1884},
  {"goto_hana", 0x59CBE8},
  {"nagano_momoha", 0xF7EA48},
};

static const struct Member juice_juice_members[] = {
  {"dambara_ruru", 0xFC4C02},
  {"inoue_rei", 0xFFFFFF},
  {"kudo_yume", 0xF57EB6},
  {"matsunaga_riai", 0x0033A0},
  {"arisawa_ichika", 0xB9D9EB},
  {"irie_risa", 0xC1A7E2},
  {"ebata_kisaki", 0xFDDA24},
  {"ishiyama_sakura", 0x582C83},
  {"endo_akari", 0x00C7B1},
  {"kawashima_mifu", 0xE70033},
  {"hayashi_niina", 0x00B140},
};

static const struct Member camelia_factory_members[] = {
  {"tanimoto_ami", 0xC1A7E2},
  {"ono_mizuho", 0x00B2A9},
  {"onoda_saori", 0xF99FC9},
  {"akiyama_mao", 0xE70033},
  {"kasai_yuumi", 0x582C83},
  {"fukuda_marine", 0x0033A0},
  {"yofu_runo", 0xFFCD00},
  {"ishii_mihane", 0xFFFFFF},
  {"murata_yuu", 0xF2D4D7},
  {"doi_fuka", 0x00B140},
  {"nishimura_itsuki", 0xF7EA48},
};

static const struct Member beyooooonds_members[] = {
  {"nishida_shiori", 0xDA1884},
  {"eguchi_saya", 0xFDDA24},
  {"maeda_kokoro", 0x59CBE8},
  {"okamura_minami", 0xF57EB6},
  {"kiyono_momohime", 0xFC4C02},
  {"hirai_miyo", 0x582C83},
  {"kobayashi_honoka", 0x007749},
  {"satoyoshi_utano", 0x005EB8},
  {"kojima_hana", 0xFFFFFF},
  {"otsubo_mano", 0xD0DF00},
  {"sugiyama_yuna", 0xE70033},
};

static const struct Member ocha_norma_members[] = {
  {"saito_madoka", 0x59CBE8},
  {"hiromoto_ruli", 0xF7EA48},
  {"yonemura_kirara", 0xE70033},
  {"kubota_nanami", 0xF57EB6},
  {"nakayama_natsume", 0xFFFFFF},
  {"nishizaki_miku", 0x582C83},
  {"kitahara_momo", 0xD0DF00},
  {"tsutsui_roko", 0x0033A0},
};

static const struct Member rosy_chronicle_members[] = {
  {"hashida_honoka", 0xFFFFFF},
  {"yoshida_hinoha", 0xE70033},
  {"onoda_karin", 0xF57EB6},
  {"murakoshi_ayana", 0xC1A7E2},
  {"uemura_hasumi", 0xFC4C02},
  {"matsubara_yulia", 0xB9D9EB},
  {"shimakawa_hana", 0x00B140},
  {"kamimura_rena", 0xF7EA48},
  {"soma_yume", 0x005EB8},
};

const Group groups[GROUP_PAGE_NUM] = {
  {"Morning Musume", sizeof(morning_musume_members) / sizeof(morning_musume_members[0]), morning_musume_members},
  {"Angerme", sizeof(angerme_members) / sizeof(angerme_members[0]), angerme_members},
  {"Juice=Juice", sizeof(juice_juice_members) / sizeof(juice_juice_members[0]), juice_juice_members},
  {"Camelia Factory", sizeof(camelia_factory_members) / sizeof(camelia_factory_members[0]), camelia_factory_members},
  {"BEYOOOOONDS", sizeof(beyooooonds_members) / sizeof(beyooooonds_members[0]), beyooooonds_members},
  {"OCHA NORMA", sizeof(ocha_norma_members) / sizeof(ocha_norma_members[0]), ocha_norma_members},
  {"Rosy Chronicle", sizeof(rosy_chronicle_members) / sizeof(rosy_chronicle_members[0]), rosy_chronicle_members},
};
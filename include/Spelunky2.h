#pragma once

#include <QMetaEnum>
#include <cstdint>
#include <qnamespace.h>
#include <string>
#include <unordered_map>
#include <vector>

class EntityDB;

static constexpr uint8_t gsColField = 0;
static constexpr uint8_t gsColValue = 1;
static constexpr uint8_t gsColValueHex = 2;
static constexpr uint8_t gsColMemoryOffset = 3;
static constexpr uint8_t gsColType = 4;

static const uint16_t gsRoleField = Qt::UserRole + gsColField;
static const uint16_t gsRoleValue = Qt::UserRole + gsColValue;
static const uint16_t gsRoleValueHex = Qt::UserRole + gsColValueHex;
static const uint16_t gsRoleType = Qt::UserRole + gsColMemoryOffset;
static const uint16_t gsRoleMemoryOffset = Qt::UserRole + gsColType;
static const uint16_t gsRoleRawValue = Qt::UserRole + 10;
static const uint16_t gsRoleUID = Qt::UserRole + 11;

// new types need to be added to
// - the MemoryFieldType enum below
// - the string representation of the type in gsMemoryFieldTypeToStringMapping
// - its fields in a vector<MemoryField> below
// - MemoryMappedData.cpp (setOffsetForField)
// - TreeViewMemoryFields.cpp (updateValueForField and addMemoryField)

enum class MemoryFieldType
{
    CodePointer,
    DataPointer,
    Byte,
    UnsignedByte,
    Word,
    UnsignedWord,
    Dword,
    UnsignedDword,
    Qword,
    UnsignedQword,
    Float,
    Bool,
    Flags32,
    Skip,
    Rect,
    StateIllumination,
    StateSaturationVignette,
    StateItems,
    Layer,
    EntityPointer,
    EntityDBPointer,
    EntityDBID,
    Vector,
    Color,
    TexturePointer,
    ConstCharPointerPointer,
    Map,
    ClassEntity,
    ClassMovable,
    ClassMonster
};
Q_DECLARE_METATYPE(MemoryFieldType)

// clang-format off
const static std::unordered_map<MemoryFieldType, std::string> gsMemoryFieldTypeToStringMapping = {
    {MemoryFieldType::CodePointer, "Code pointer"},
    {MemoryFieldType::DataPointer, "Data pointer"},
    {MemoryFieldType::Byte, "8-bit"},
    {MemoryFieldType::UnsignedByte, "8-bit unsigned"},
    {MemoryFieldType::Word, "16-bit"},
    {MemoryFieldType::UnsignedWord, "16-bit unsigned"},
    {MemoryFieldType::Dword, "32-bit"},
    {MemoryFieldType::UnsignedDword, "32-bit unsigned"},
    {MemoryFieldType::Qword, "64-bit"},
    {MemoryFieldType::UnsignedQword, "64-bit unsigned"},
    {MemoryFieldType::Float, "Float"},
    {MemoryFieldType::Bool, "Bool"},
    {MemoryFieldType::Flags32, "32-bit flags"},
    {MemoryFieldType::Rect, "Rectangle"},
    {MemoryFieldType::StateIllumination, "Illumination"},
    {MemoryFieldType::StateSaturationVignette, "Saturation/Vignette"},
    {MemoryFieldType::StateItems, "Items"},
    {MemoryFieldType::Layer, "Layer"},
    {MemoryFieldType::EntityPointer, "Entity pointer"},
    {MemoryFieldType::EntityDBPointer, "EntityDB pointer"},
    {MemoryFieldType::EntityDBID, "EntityDB ID"},
    {MemoryFieldType::Vector, "Vector"},
    {MemoryFieldType::Color, "Color"},
    {MemoryFieldType::TexturePointer, "Texture pointer"},
    {MemoryFieldType::ConstCharPointerPointer, "Const char**"},
    {MemoryFieldType::Map, "std::map<>"},
    {MemoryFieldType::ClassEntity, "Entity"},
    {MemoryFieldType::ClassMovable, "Movable"},
    {MemoryFieldType::ClassMonster, "Monster"},
};
// clang-format on

struct MemoryField
{
    std::string name;
    MemoryFieldType type;
    uint64_t extraInfo = 0;
};

// clang-format off
const std::vector<MemoryField> gsEntityDBFields = {
    {"create_func", MemoryFieldType::CodePointer}, 
    {"destroy_func", MemoryFieldType::CodePointer},
    {"field_10", MemoryFieldType::UnsignedDword},
    {"id", MemoryFieldType::EntityDBID},
    {"search_flags", MemoryFieldType::Flags32},
    {"width", MemoryFieldType::Float},
    {"height", MemoryFieldType::Float},
    {"draw_depth", MemoryFieldType::UnsignedByte},
    {"default_b3f", MemoryFieldType::UnsignedByte},
    {"field_26", MemoryFieldType::Word},
    {"rect_collision", MemoryFieldType::Rect},
    {"field_3C", MemoryFieldType::Dword},
    {"field_40", MemoryFieldType::Dword},
    {"field_44", MemoryFieldType::Dword},
    {"default_flags", MemoryFieldType::Flags32},
    {"default_more_flags", MemoryFieldType::Flags32},
    {"properties_flags", MemoryFieldType::Flags32},
    {"friction", MemoryFieldType::Float},
    {"elasticity", MemoryFieldType::Float},
    {"weight", MemoryFieldType::Float},
    {"field_60", MemoryFieldType::UnsignedByte},
    {"field_61", MemoryFieldType::UnsignedByte},
    {"field_62", MemoryFieldType::UnsignedByte},
    {"field_63", MemoryFieldType::UnsignedByte},
    {"acceleration", MemoryFieldType::Float},
    {"max_speed", MemoryFieldType::Float},
    {"sprint_factor", MemoryFieldType::Float},
    {"jump", MemoryFieldType::Float},
    {"_a", MemoryFieldType::Float},
    {"_b", MemoryFieldType::Float},
    {"_c", MemoryFieldType::Float},
    {"_d", MemoryFieldType::Float},
    {"texture", MemoryFieldType::Dword},
    {"technique", MemoryFieldType::Dword},
    {"tile_x", MemoryFieldType::Dword},
    {"tile_y", MemoryFieldType::Dword},
    {"damage", MemoryFieldType::UnsignedByte},
    {"life", MemoryFieldType::UnsignedByte},
    {"field_96", MemoryFieldType::UnsignedByte},
    {"field_97", MemoryFieldType::UnsignedByte},
    {"field_98", MemoryFieldType::UnsignedByte},
    {"field_99", MemoryFieldType::UnsignedByte},
    {"field_9A", MemoryFieldType::UnsignedByte},
    {"field_9B", MemoryFieldType::UnsignedByte},
    {"description", MemoryFieldType::Dword},
    {"field_a0", MemoryFieldType::Dword},
    {"field_a4", MemoryFieldType::Dword},
    {"field_a8", MemoryFieldType::Float},
    {"field_AC", MemoryFieldType::Dword},
    {"-", MemoryFieldType::Skip, 0x40},
    {"attachOffsetX", MemoryFieldType::Float},
    {"attachOffsetY", MemoryFieldType::Float},
    {"init", MemoryFieldType::UnsignedByte},
    {"field_19", MemoryFieldType::UnsignedByte},
    {"field_1a", MemoryFieldType::UnsignedByte},
    {"field_1b", MemoryFieldType::UnsignedByte},
    {"field_1c", MemoryFieldType::Dword},
};

static const std::vector<MemoryField> gsRectFields = {
    {"masks", MemoryFieldType::UnsignedDword}, 
    {"up_minus_down", MemoryFieldType::Float}, 
    {"side", MemoryFieldType::Float}, 
    {"up_plus_down", MemoryFieldType::Float}, 
    {"field_10", MemoryFieldType::UnsignedByte}, 
    {"field_11", MemoryFieldType::UnsignedByte}, 
    {"field_12", MemoryFieldType::UnsignedWord}
};

static const std::vector<MemoryField> gsStateFields = {
    {"p00", MemoryFieldType::DataPointer}, 
    {"screen_last", MemoryFieldType::UnsignedDword}, 
    {"screen", MemoryFieldType::UnsignedDword}, 
    {"screen_next", MemoryFieldType::UnsignedDword}, 
    {"loading", MemoryFieldType::UnsignedDword},
    {"illumination", MemoryFieldType::StateIllumination},
    {"i20", MemoryFieldType::Dword},
    {"fadeout", MemoryFieldType::UnsignedDword},
    {"fadein", MemoryFieldType::UnsignedDword},
    {"i2c", MemoryFieldType::Dword},
    {"ingame", MemoryFieldType::Bool},
    {"playing", MemoryFieldType::Bool},
    {"pause", MemoryFieldType::Bool},
    {"b33", MemoryFieldType::UnsignedByte},
    {"i34", MemoryFieldType::Dword},
    {"quest_flags", MemoryFieldType::Flags32},
    {"i3c", MemoryFieldType::Dword},
    {"i40", MemoryFieldType::Dword},
    {"i44", MemoryFieldType::Dword},
    {"w", MemoryFieldType::UnsignedDword},
    {"h", MemoryFieldType::UnsignedDword},
    {"kali_favor", MemoryFieldType::Byte},
    {"kali_status", MemoryFieldType::Byte},
    {"kali_altars_destroyed", MemoryFieldType::Byte},
    {"b4f", MemoryFieldType::UnsignedByte},
    {"i50", MemoryFieldType::Dword},
    {"i54", MemoryFieldType::Dword},
    {"world_start", MemoryFieldType::UnsignedByte},
    {"level_start", MemoryFieldType::UnsignedByte},
    {"theme_start", MemoryFieldType::UnsignedByte},
    {"b5f", MemoryFieldType::UnsignedByte},
    {"seed", MemoryFieldType::UnsignedDword},
    {"time_total", MemoryFieldType::UnsignedDword},
    {"world", MemoryFieldType::UnsignedByte},
    {"world_next", MemoryFieldType::UnsignedByte},
    {"level", MemoryFieldType::UnsignedByte},
    {"level_next", MemoryFieldType::UnsignedByte},
    {"i6c", MemoryFieldType::Dword},
    {"i70", MemoryFieldType::Dword},
    {"theme", MemoryFieldType::UnsignedByte},
    {"theme_next", MemoryFieldType::UnsignedByte},
    {"win_state", MemoryFieldType::UnsignedByte},
    {"b73", MemoryFieldType::UnsignedByte},
    {"i74", MemoryFieldType::Dword},
    {"shoppie_aggro", MemoryFieldType::UnsignedByte},
    {"shoppie_aggro_levels", MemoryFieldType::UnsignedByte},
    {"merchant_aggro", MemoryFieldType::UnsignedByte},
    {"merchant_pad", MemoryFieldType::UnsignedByte},
    {"b7c", MemoryFieldType::UnsignedByte},
    {"b7d", MemoryFieldType::UnsignedByte},
    {"kills_npc", MemoryFieldType::UnsignedByte},
    {"level_count", MemoryFieldType::UnsignedByte},
    {"-", MemoryFieldType::Skip, 0x970},
    {"journal_flags", MemoryFieldType::Flags32},
    {"i9f0", MemoryFieldType::Dword},
    {"i9f4", MemoryFieldType::Dword},
    {"time_last_level", MemoryFieldType::UnsignedDword},
    {"time_level", MemoryFieldType::UnsignedDword},
    {"ia00", MemoryFieldType::Dword},
    {"money_last_levels", MemoryFieldType::UnsignedDword},
    {"hud_flags", MemoryFieldType::Flags32},
    {"-", MemoryFieldType::Skip, 0x12b0 - 0xa14},
    {"items", MemoryFieldType::StateItems},
    {"-", MemoryFieldType::Skip, 8},
    {"layer0", MemoryFieldType::Layer}, 
    {"layer1", MemoryFieldType::Layer}, 
};

static const std::vector<MemoryField> gsStateIlluminationFields = {
    {"saturation_vignette_0", MemoryFieldType::StateSaturationVignette}, 
    {"saturation_vignette_1", MemoryFieldType::StateSaturationVignette}, 
    {"saturation_vignette_2", MemoryFieldType::StateSaturationVignette}, 
    {"saturation_vignette_3", MemoryFieldType::StateSaturationVignette}, 
    {"brightness1", MemoryFieldType::Float}, 
    {"brightness2", MemoryFieldType::Float}, 
    {"something_min", MemoryFieldType::Float}, 
    {"something_max", MemoryFieldType::Float}, 
    {"unknown_empty", MemoryFieldType::UnsignedQword}, 
    {"unknown_float", MemoryFieldType::Float}, 
    {"unknown_nan", MemoryFieldType::Float}, 
    {"unknown_timer", MemoryFieldType::UnsignedDword}, 
    {"frontlayer_global_illumination", MemoryFieldType::UnsignedByte},
    {"unknown_illumination1", MemoryFieldType::UnsignedByte},
    {"backlayer_global_illumination", MemoryFieldType::UnsignedByte},
    {"unknown_illumination2", MemoryFieldType::UnsignedByte},
    {"unknown_int1", MemoryFieldType::UnsignedDword},
    {"unknown_int2", MemoryFieldType::UnsignedDword}
};

static const std::vector<MemoryField> gsStateSaturationVignetteFields = {
    {"red", MemoryFieldType::Float}, 
    {"green", MemoryFieldType::Float}, 
    {"blue", MemoryFieldType::Float}, 
    {"vignette_aperture", MemoryFieldType::Float}
};

static const std::vector<MemoryField> gsStateItemsFields = {
    {"__vftable", MemoryFieldType::DataPointer}, 
    {"player1", MemoryFieldType::EntityPointer},
    {"player2", MemoryFieldType::EntityPointer}, 
    {"player3", MemoryFieldType::EntityPointer}, 
    {"player4", MemoryFieldType::EntityPointer}, 
};

static const std::vector<MemoryField> gsLayerFields = {
    {"__vftable", MemoryFieldType::DataPointer}, 
    {"first_entity*", MemoryFieldType::DataPointer}, 
    {"b", MemoryFieldType::DataPointer}, 
    {"capacity", MemoryFieldType::Dword}, 
    {"size", MemoryFieldType::Dword}, 
};

static const std::vector<MemoryField> gsEntityFields = {
    {"__vftable", MemoryFieldType::DataPointer}, 
    {"type", MemoryFieldType::EntityDBPointer}, 
    {"overlay", MemoryFieldType::EntityPointer}, 
    {"items", MemoryFieldType::Vector}, 
    {"flags", MemoryFieldType::Flags32}, 
    {"more_flags", MemoryFieldType::Flags32}, 
    {"uid", MemoryFieldType::Dword}, 
    {"animation_frame", MemoryFieldType::UnsignedByte}, 
    {"b3d", MemoryFieldType::UnsignedByte}, 
    {"draw_depth", MemoryFieldType::UnsignedByte}, 
    {"b3f", MemoryFieldType::UnsignedByte}, 
    {"x", MemoryFieldType::Float}, 
    {"y", MemoryFieldType::Float}, 
    {"w", MemoryFieldType::Float}, 
    {"h", MemoryFieldType::Float}, 
    {"f50", MemoryFieldType::Float}, 
    {"f54", MemoryFieldType::Float}, 
    {"color", MemoryFieldType::Color}, 
    {"offsetx", MemoryFieldType::Float}, 
    {"offsety", MemoryFieldType::Float}, 
    {"hitboxx", MemoryFieldType::Float}, 
    {"hitboxy", MemoryFieldType::Float}, 
    {"duckmask", MemoryFieldType::UnsignedDword}, 
    {"angle", MemoryFieldType::Float}, 
    {"p80", MemoryFieldType::DataPointer}, 
    {"texture", MemoryFieldType::TexturePointer}, 
    {"tilew", MemoryFieldType::Float}, 
    {"tileh", MemoryFieldType::Float}, 
    {"camera_layer", MemoryFieldType::UnsignedByte}, 
    {"b99", MemoryFieldType::UnsignedByte}, 
    {"b9a", MemoryFieldType::UnsignedByte}, 
    {"b9b", MemoryFieldType::UnsignedByte}, 
    {"i9c", MemoryFieldType::UnsignedDword}, 
};

static const std::vector<MemoryField> gsVectorFields = {
    {"heap", MemoryFieldType::DataPointer},
    {"begin", MemoryFieldType::DataPointer},
    {"size", MemoryFieldType::UnsignedDword},
    {"count", MemoryFieldType::UnsignedDword}
};

static const std::vector<MemoryField> gsColorFields = {
    {"red", MemoryFieldType::Float}, 
    {"green", MemoryFieldType::Float}, 
    {"blue", MemoryFieldType::Float}, 
    {"alpha", MemoryFieldType::Float}
};

static const std::vector<MemoryField> gsTextureFields = {
    {"id", MemoryFieldType::UnsignedQword}, 
    {"name", MemoryFieldType::ConstCharPointerPointer}, 
    {"width", MemoryFieldType::UnsignedDword}, 
    {"height", MemoryFieldType::UnsignedDword}, 
    {"num_tiles_width", MemoryFieldType::UnsignedDword}, 
    {"num_tiles_height", MemoryFieldType::UnsignedDword}, 
    {"offset_x_weird_math", MemoryFieldType::Float},
    {"offset_y_weird_math", MemoryFieldType::Float},
    {"tile_width_fraction", MemoryFieldType::Float},
    {"tile_height_fraction", MemoryFieldType::Float},
    {"tile_width_minus_one_fraction", MemoryFieldType::Float},
    {"tile_height_minus_one_fraction", MemoryFieldType::Float},
    {"one_over_width", MemoryFieldType::Float},
    {"one_over_height", MemoryFieldType::Float}
};

static const std::vector<MemoryField> gsMapFields = {
    {"items", MemoryFieldType::DataPointer}, 
    {"size", MemoryFieldType::UnsignedQword}, 
};

static const std::vector<MemoryField> gsMovableFields = {
    {"pa0", MemoryFieldType::Map}, 
    {"pb0", MemoryFieldType::Map}, 
    {"anim_func", MemoryFieldType::DataPointer},
    {"ic8", MemoryFieldType::Dword}, 
    {"icc", MemoryFieldType::Dword}, 
    {"movex", MemoryFieldType::Float}, 
    {"movey", MemoryFieldType::Float}, 
    {"buttons", MemoryFieldType::UnsignedDword}, 
    {"stand_counter", MemoryFieldType::UnsignedDword}, 
    {"fe0", MemoryFieldType::Float},
    {"price", MemoryFieldType::Dword},
    {"owner_uid", MemoryFieldType::Dword},
    {"last_owner_uid", MemoryFieldType::Dword}, 
    {"animation_func", MemoryFieldType::DataPointer}, 
    {"idle_counter", MemoryFieldType::UnsignedDword}, 
    {"standing_on_uid", MemoryFieldType::Dword}, 
    {"velocityx", MemoryFieldType::Float}, 
    {"velocityy", MemoryFieldType::Float}, 
    {"holding_uid", MemoryFieldType::Dword}, 
    {"state", MemoryFieldType::UnsignedByte}, 
    {"last_state", MemoryFieldType::UnsignedByte}, 
    {"move_state", MemoryFieldType::UnsignedByte}, 
    {"health", MemoryFieldType::UnsignedByte}, 
    {"stun_timer", MemoryFieldType::UnsignedWord}, 
    {"stun_state", MemoryFieldType::UnsignedWord}, 
    {"some_state", MemoryFieldType::UnsignedDword}, 
    {"poison_tick_timer", MemoryFieldType::Word}, 
    {"unknown_timer", MemoryFieldType::Word}, 
    {"i11c", MemoryFieldType::Dword}, 
    {"i120", MemoryFieldType::Dword}, 
    {"b124", MemoryFieldType::UnsignedByte}, 
    {"airtime", MemoryFieldType::UnsignedByte}, 
    {"b126", MemoryFieldType::UnsignedByte}, 
    {"b127", MemoryFieldType::UnsignedByte}
};

static const std::vector<MemoryField> gsMonsterFields = {
    {"inside", MemoryFieldType::Map}
};

// a mapping of what type is the parent class of a specific type
static const std::unordered_map<MemoryFieldType, MemoryFieldType> gsEntityClassHierarchy = {
    {MemoryFieldType::ClassMovable, MemoryFieldType::ClassEntity},
    {MemoryFieldType::ClassMonster, MemoryFieldType::ClassMovable},
};

// the list of fields belonging to a type
static const std::unordered_map<MemoryFieldType, std::vector<MemoryField>> gsEntityClassFields = {
    {MemoryFieldType::ClassEntity, gsEntityFields},
    {MemoryFieldType::ClassMovable, gsMovableFields},
    {MemoryFieldType::ClassMonster, gsMonsterFields},
};

// the default types of a specific entity; specify a regex to match more than one at the same time
static const std::unordered_map<std::string, MemoryFieldType> gsDefaultEntityClassTypes = {
    { "CHAR_.*", MemoryFieldType::ClassMonster }
};

// clang-format on

size_t spelunky2AfterBundle();
size_t spelunky2AfterBundleSize();
std::string getEntityName(size_t offset, EntityDB* entityDB);
uint32_t getEntityTypeID(size_t offset);

// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_DRAGONBONES_FLATBUFFERS_H_
#define FLATBUFFERS_GENERATED_DRAGONBONES_FLATBUFFERS_H_

#include "flatbuffers/flatbuffers.h"


namespace flatbuffers {

struct Transform;
struct ColorTransform;
struct Dragonbones;
struct Armature;
struct Bone;
struct Skin;
struct Slot;
struct Display;
struct Animation;
struct Frame;
struct Timeline;
struct Timeline_Frame;

MANUALLY_ALIGNED_STRUCT(4) Transform FLATBUFFERS_FINAL_CLASS {
 private:
  float x_;
  float y_;
  float skX_;
  float skY_;
  float scX_;
  float scY_;
  float pX_;
  float pY_;

 public:
  Transform(float x, float y, float skX, float skY, float scX, float scY, float pX, float pY)
    : x_(flatbuffers::EndianScalar(x)), y_(flatbuffers::EndianScalar(y)), skX_(flatbuffers::EndianScalar(skX)), skY_(flatbuffers::EndianScalar(skY)), scX_(flatbuffers::EndianScalar(scX)), scY_(flatbuffers::EndianScalar(scY)), pX_(flatbuffers::EndianScalar(pX)), pY_(flatbuffers::EndianScalar(pY)) { }

  float x() const { return flatbuffers::EndianScalar(x_); }
  float y() const { return flatbuffers::EndianScalar(y_); }
  float skX() const { return flatbuffers::EndianScalar(skX_); }
  float skY() const { return flatbuffers::EndianScalar(skY_); }
  float scX() const { return flatbuffers::EndianScalar(scX_); }
  float scY() const { return flatbuffers::EndianScalar(scY_); }
  float pX() const { return flatbuffers::EndianScalar(pX_); }
  float pY() const { return flatbuffers::EndianScalar(pY_); }
};
STRUCT_END(Transform, 32);

MANUALLY_ALIGNED_STRUCT(2) ColorTransform FLATBUFFERS_FINAL_CLASS {
 private:
  uint16_t aO_;
  uint16_t rO_;
  uint16_t gO_;
  uint16_t bO_;
  uint16_t aM_;
  uint16_t rM_;
  uint16_t gM_;
  uint16_t bM_;

 public:
  ColorTransform(uint16_t aO, uint16_t rO, uint16_t gO, uint16_t bO, uint16_t aM, uint16_t rM, uint16_t gM, uint16_t bM)
    : aO_(flatbuffers::EndianScalar(aO)), rO_(flatbuffers::EndianScalar(rO)), gO_(flatbuffers::EndianScalar(gO)), bO_(flatbuffers::EndianScalar(bO)), aM_(flatbuffers::EndianScalar(aM)), rM_(flatbuffers::EndianScalar(rM)), gM_(flatbuffers::EndianScalar(gM)), bM_(flatbuffers::EndianScalar(bM)) { }

  uint16_t aO() const { return flatbuffers::EndianScalar(aO_); }
  uint16_t rO() const { return flatbuffers::EndianScalar(rO_); }
  uint16_t gO() const { return flatbuffers::EndianScalar(gO_); }
  uint16_t bO() const { return flatbuffers::EndianScalar(bO_); }
  uint16_t aM() const { return flatbuffers::EndianScalar(aM_); }
  uint16_t rM() const { return flatbuffers::EndianScalar(rM_); }
  uint16_t gM() const { return flatbuffers::EndianScalar(gM_); }
  uint16_t bM() const { return flatbuffers::EndianScalar(bM_); }
};
STRUCT_END(ColorTransform, 16);

struct Dragonbones FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(4); }
  const flatbuffers::String *version() const { return GetPointer<const flatbuffers::String *>(6); }
  uint16_t frameRate() const { return GetField<uint16_t>(8, 0); }
  uint8_t isGlobal() const { return GetField<uint8_t>(10, 1); }
  const flatbuffers::Vector<flatbuffers::Offset<Armature>> *armature() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Armature>> *>(12); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* name */) &&
           verifier.Verify(name()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 6 /* version */) &&
           verifier.Verify(version()) &&
           VerifyField<uint16_t>(verifier, 8 /* frameRate */) &&
           VerifyField<uint8_t>(verifier, 10 /* isGlobal */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 12 /* armature */) &&
           verifier.Verify(armature()) &&
           verifier.VerifyVectorOfTables(armature()) &&
           verifier.EndTable();
  }
};

struct DragonbonesBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(4, name); }
  void add_version(flatbuffers::Offset<flatbuffers::String> version) { fbb_.AddOffset(6, version); }
  void add_frameRate(uint16_t frameRate) { fbb_.AddElement<uint16_t>(8, frameRate, 0); }
  void add_isGlobal(uint8_t isGlobal) { fbb_.AddElement<uint8_t>(10, isGlobal, 1); }
  void add_armature(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Armature>>> armature) { fbb_.AddOffset(12, armature); }
  DragonbonesBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  DragonbonesBuilder &operator=(const DragonbonesBuilder &);
  flatbuffers::Offset<Dragonbones> Finish() {
    auto o = flatbuffers::Offset<Dragonbones>(fbb_.EndTable(start_, 5));
    return o;
  }
};

inline flatbuffers::Offset<Dragonbones> CreateDragonbones(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<flatbuffers::String> name = 0,
   flatbuffers::Offset<flatbuffers::String> version = 0,
   uint16_t frameRate = 0,
   uint8_t isGlobal = 1,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Armature>>> armature = 0) {
  DragonbonesBuilder builder_(_fbb);
  builder_.add_armature(armature);
  builder_.add_version(version);
  builder_.add_name(name);
  builder_.add_frameRate(frameRate);
  builder_.add_isGlobal(isGlobal);
  return builder_.Finish();
}

struct Armature FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(4); }
  const flatbuffers::Vector<flatbuffers::Offset<Bone>> *bone() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Bone>> *>(6); }
  const flatbuffers::Vector<flatbuffers::Offset<Animation>> *animation() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Animation>> *>(8); }
  const flatbuffers::Vector<flatbuffers::Offset<Skin>> *skin() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Skin>> *>(10); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* name */) &&
           verifier.Verify(name()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 6 /* bone */) &&
           verifier.Verify(bone()) &&
           verifier.VerifyVectorOfTables(bone()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 8 /* animation */) &&
           verifier.Verify(animation()) &&
           verifier.VerifyVectorOfTables(animation()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 10 /* skin */) &&
           verifier.Verify(skin()) &&
           verifier.VerifyVectorOfTables(skin()) &&
           verifier.EndTable();
  }
};

struct ArmatureBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(4, name); }
  void add_bone(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Bone>>> bone) { fbb_.AddOffset(6, bone); }
  void add_animation(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Animation>>> animation) { fbb_.AddOffset(8, animation); }
  void add_skin(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Skin>>> skin) { fbb_.AddOffset(10, skin); }
  ArmatureBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  ArmatureBuilder &operator=(const ArmatureBuilder &);
  flatbuffers::Offset<Armature> Finish() {
    auto o = flatbuffers::Offset<Armature>(fbb_.EndTable(start_, 4));
    return o;
  }
};

inline flatbuffers::Offset<Armature> CreateArmature(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<flatbuffers::String> name = 0,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Bone>>> bone = 0,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Animation>>> animation = 0,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Skin>>> skin = 0) {
  ArmatureBuilder builder_(_fbb);
  builder_.add_skin(skin);
  builder_.add_animation(animation);
  builder_.add_bone(bone);
  builder_.add_name(name);
  return builder_.Finish();
}

struct Bone FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(4); }
  const flatbuffers::String *parent() const { return GetPointer<const flatbuffers::String *>(6); }
  int16_t length() const { return GetField<int16_t>(8, 0); }
  const Transform *transform() const { return GetStruct<const Transform *>(10); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* name */) &&
           verifier.Verify(name()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 6 /* parent */) &&
           verifier.Verify(parent()) &&
           VerifyField<int16_t>(verifier, 8 /* length */) &&
           VerifyField<Transform>(verifier, 10 /* transform */) &&
           verifier.EndTable();
  }
};

struct BoneBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(4, name); }
  void add_parent(flatbuffers::Offset<flatbuffers::String> parent) { fbb_.AddOffset(6, parent); }
  void add_length(int16_t length) { fbb_.AddElement<int16_t>(8, length, 0); }
  void add_transform(const Transform *transform) { fbb_.AddStruct(10, transform); }
  BoneBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  BoneBuilder &operator=(const BoneBuilder &);
  flatbuffers::Offset<Bone> Finish() {
    auto o = flatbuffers::Offset<Bone>(fbb_.EndTable(start_, 4));
    return o;
  }
};

inline flatbuffers::Offset<Bone> CreateBone(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<flatbuffers::String> name = 0,
   flatbuffers::Offset<flatbuffers::String> parent = 0,
   int16_t length = 0,
   const Transform *transform = 0) {
  BoneBuilder builder_(_fbb);
  builder_.add_transform(transform);
  builder_.add_parent(parent);
  builder_.add_name(name);
  builder_.add_length(length);
  return builder_.Finish();
}

struct Skin FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(4); }
  const flatbuffers::Vector<flatbuffers::Offset<Slot>> *slot() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Slot>> *>(6); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* name */) &&
           verifier.Verify(name()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 6 /* slot */) &&
           verifier.Verify(slot()) &&
           verifier.VerifyVectorOfTables(slot()) &&
           verifier.EndTable();
  }
};

struct SkinBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(4, name); }
  void add_slot(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Slot>>> slot) { fbb_.AddOffset(6, slot); }
  SkinBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  SkinBuilder &operator=(const SkinBuilder &);
  flatbuffers::Offset<Skin> Finish() {
    auto o = flatbuffers::Offset<Skin>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<Skin> CreateSkin(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<flatbuffers::String> name = 0,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Slot>>> slot = 0) {
  SkinBuilder builder_(_fbb);
  builder_.add_slot(slot);
  builder_.add_name(name);
  return builder_.Finish();
}

struct Slot FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(4); }
  const flatbuffers::String *parent() const { return GetPointer<const flatbuffers::String *>(6); }
  const flatbuffers::String *blendMode() const { return GetPointer<const flatbuffers::String *>(8); }
  float z() const { return GetField<float>(10, 0); }
  const flatbuffers::Vector<flatbuffers::Offset<Display>> *display() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Display>> *>(12); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* name */) &&
           verifier.Verify(name()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 6 /* parent */) &&
           verifier.Verify(parent()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 8 /* blendMode */) &&
           verifier.Verify(blendMode()) &&
           VerifyField<float>(verifier, 10 /* z */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 12 /* display */) &&
           verifier.Verify(display()) &&
           verifier.VerifyVectorOfTables(display()) &&
           verifier.EndTable();
  }
};

struct SlotBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(4, name); }
  void add_parent(flatbuffers::Offset<flatbuffers::String> parent) { fbb_.AddOffset(6, parent); }
  void add_blendMode(flatbuffers::Offset<flatbuffers::String> blendMode) { fbb_.AddOffset(8, blendMode); }
  void add_z(float z) { fbb_.AddElement<float>(10, z, 0); }
  void add_display(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Display>>> display) { fbb_.AddOffset(12, display); }
  SlotBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  SlotBuilder &operator=(const SlotBuilder &);
  flatbuffers::Offset<Slot> Finish() {
    auto o = flatbuffers::Offset<Slot>(fbb_.EndTable(start_, 5));
    return o;
  }
};

inline flatbuffers::Offset<Slot> CreateSlot(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<flatbuffers::String> name = 0,
   flatbuffers::Offset<flatbuffers::String> parent = 0,
   flatbuffers::Offset<flatbuffers::String> blendMode = 0,
   float z = 0,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Display>>> display = 0) {
  SlotBuilder builder_(_fbb);
  builder_.add_display(display);
  builder_.add_z(z);
  builder_.add_blendMode(blendMode);
  builder_.add_parent(parent);
  builder_.add_name(name);
  return builder_.Finish();
}

struct Display FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const flatbuffers::String *type() const { return GetPointer<const flatbuffers::String *>(4); }
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(6); }
  const Transform *transform() const { return GetStruct<const Transform *>(8); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* type */) &&
           verifier.Verify(type()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 6 /* name */) &&
           verifier.Verify(name()) &&
           VerifyField<Transform>(verifier, 8 /* transform */) &&
           verifier.EndTable();
  }
};

struct DisplayBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_type(flatbuffers::Offset<flatbuffers::String> type) { fbb_.AddOffset(4, type); }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(6, name); }
  void add_transform(const Transform *transform) { fbb_.AddStruct(8, transform); }
  DisplayBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  DisplayBuilder &operator=(const DisplayBuilder &);
  flatbuffers::Offset<Display> Finish() {
    auto o = flatbuffers::Offset<Display>(fbb_.EndTable(start_, 3));
    return o;
  }
};

inline flatbuffers::Offset<Display> CreateDisplay(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<flatbuffers::String> type = 0,
   flatbuffers::Offset<flatbuffers::String> name = 0,
   const Transform *transform = 0) {
  DisplayBuilder builder_(_fbb);
  builder_.add_transform(transform);
  builder_.add_name(name);
  builder_.add_type(type);
  return builder_.Finish();
}

struct Animation FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(4); }
  const flatbuffers::String *tweenEasing() const { return GetPointer<const flatbuffers::String *>(6); }
  float fadeInTime() const { return GetField<float>(8, 0.0); }
  float scale() const { return GetField<float>(10, 1.0); }
  uint32_t loop() const { return GetField<uint32_t>(12, 1); }
  uint16_t duration() const { return GetField<uint16_t>(14, 0); }
  uint16_t autoTween() const { return GetField<uint16_t>(16, 1); }
  const flatbuffers::Vector<flatbuffers::Offset<Frame>> *frame() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Frame>> *>(18); }
  const flatbuffers::Vector<flatbuffers::Offset<Timeline>> *timeline() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Timeline>> *>(20); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* name */) &&
           verifier.Verify(name()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 6 /* tweenEasing */) &&
           verifier.Verify(tweenEasing()) &&
           VerifyField<float>(verifier, 8 /* fadeInTime */) &&
           VerifyField<float>(verifier, 10 /* scale */) &&
           VerifyField<uint32_t>(verifier, 12 /* loop */) &&
           VerifyField<uint16_t>(verifier, 14 /* duration */) &&
           VerifyField<uint16_t>(verifier, 16 /* autoTween */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 18 /* frame */) &&
           verifier.Verify(frame()) &&
           verifier.VerifyVectorOfTables(frame()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 20 /* timeline */) &&
           verifier.Verify(timeline()) &&
           verifier.VerifyVectorOfTables(timeline()) &&
           verifier.EndTable();
  }
};

struct AnimationBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(4, name); }
  void add_tweenEasing(flatbuffers::Offset<flatbuffers::String> tweenEasing) { fbb_.AddOffset(6, tweenEasing); }
  void add_fadeInTime(float fadeInTime) { fbb_.AddElement<float>(8, fadeInTime, 0.0); }
  void add_scale(float scale) { fbb_.AddElement<float>(10, scale, 1.0); }
  void add_loop(uint32_t loop) { fbb_.AddElement<uint32_t>(12, loop, 1); }
  void add_duration(uint16_t duration) { fbb_.AddElement<uint16_t>(14, duration, 0); }
  void add_autoTween(uint16_t autoTween) { fbb_.AddElement<uint16_t>(16, autoTween, 1); }
  void add_frame(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Frame>>> frame) { fbb_.AddOffset(18, frame); }
  void add_timeline(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Timeline>>> timeline) { fbb_.AddOffset(20, timeline); }
  AnimationBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  AnimationBuilder &operator=(const AnimationBuilder &);
  flatbuffers::Offset<Animation> Finish() {
    auto o = flatbuffers::Offset<Animation>(fbb_.EndTable(start_, 9));
    return o;
  }
};

inline flatbuffers::Offset<Animation> CreateAnimation(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<flatbuffers::String> name = 0,
   flatbuffers::Offset<flatbuffers::String> tweenEasing = 0,
   float fadeInTime = 0.0,
   float scale = 1.0,
   uint32_t loop = 1,
   uint16_t duration = 0,
   uint16_t autoTween = 1,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Frame>>> frame = 0,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Timeline>>> timeline = 0) {
  AnimationBuilder builder_(_fbb);
  builder_.add_timeline(timeline);
  builder_.add_frame(frame);
  builder_.add_loop(loop);
  builder_.add_scale(scale);
  builder_.add_fadeInTime(fadeInTime);
  builder_.add_tweenEasing(tweenEasing);
  builder_.add_name(name);
  builder_.add_autoTween(autoTween);
  builder_.add_duration(duration);
  return builder_.Finish();
}

struct Frame FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const flatbuffers::String *event() const { return GetPointer<const flatbuffers::String *>(4); }
  const flatbuffers::String *sound() const { return GetPointer<const flatbuffers::String *>(6); }
  const flatbuffers::String *action() const { return GetPointer<const flatbuffers::String *>(8); }
  uint16_t duration() const { return GetField<uint16_t>(10, 0); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* event */) &&
           verifier.Verify(event()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 6 /* sound */) &&
           verifier.Verify(sound()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 8 /* action */) &&
           verifier.Verify(action()) &&
           VerifyField<uint16_t>(verifier, 10 /* duration */) &&
           verifier.EndTable();
  }
};

struct FrameBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_event(flatbuffers::Offset<flatbuffers::String> event) { fbb_.AddOffset(4, event); }
  void add_sound(flatbuffers::Offset<flatbuffers::String> sound) { fbb_.AddOffset(6, sound); }
  void add_action(flatbuffers::Offset<flatbuffers::String> action) { fbb_.AddOffset(8, action); }
  void add_duration(uint16_t duration) { fbb_.AddElement<uint16_t>(10, duration, 0); }
  FrameBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  FrameBuilder &operator=(const FrameBuilder &);
  flatbuffers::Offset<Frame> Finish() {
    auto o = flatbuffers::Offset<Frame>(fbb_.EndTable(start_, 4));
    return o;
  }
};

inline flatbuffers::Offset<Frame> CreateFrame(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<flatbuffers::String> event = 0,
   flatbuffers::Offset<flatbuffers::String> sound = 0,
   flatbuffers::Offset<flatbuffers::String> action = 0,
   uint16_t duration = 0) {
  FrameBuilder builder_(_fbb);
  builder_.add_action(action);
  builder_.add_sound(sound);
  builder_.add_event(event);
  builder_.add_duration(duration);
  return builder_.Finish();
}

struct Timeline FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(4); }
  float scale() const { return GetField<float>(6, 1); }
  float offset() const { return GetField<float>(8, 0); }
  float pX() const { return GetField<float>(10, 0); }
  float pY() const { return GetField<float>(12, 0); }
  const flatbuffers::Vector<flatbuffers::Offset<Timeline_Frame>> *frame() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Timeline_Frame>> *>(14); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* name */) &&
           verifier.Verify(name()) &&
           VerifyField<float>(verifier, 6 /* scale */) &&
           VerifyField<float>(verifier, 8 /* offset */) &&
           VerifyField<float>(verifier, 10 /* pX */) &&
           VerifyField<float>(verifier, 12 /* pY */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 14 /* frame */) &&
           verifier.Verify(frame()) &&
           verifier.VerifyVectorOfTables(frame()) &&
           verifier.EndTable();
  }
};

struct TimelineBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(4, name); }
  void add_scale(float scale) { fbb_.AddElement<float>(6, scale, 1); }
  void add_offset(float offset) { fbb_.AddElement<float>(8, offset, 0); }
  void add_pX(float pX) { fbb_.AddElement<float>(10, pX, 0); }
  void add_pY(float pY) { fbb_.AddElement<float>(12, pY, 0); }
  void add_frame(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Timeline_Frame>>> frame) { fbb_.AddOffset(14, frame); }
  TimelineBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  TimelineBuilder &operator=(const TimelineBuilder &);
  flatbuffers::Offset<Timeline> Finish() {
    auto o = flatbuffers::Offset<Timeline>(fbb_.EndTable(start_, 6));
    return o;
  }
};

inline flatbuffers::Offset<Timeline> CreateTimeline(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<flatbuffers::String> name = 0,
   float scale = 1,
   float offset = 0,
   float pX = 0,
   float pY = 0,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Timeline_Frame>>> frame = 0) {
  TimelineBuilder builder_(_fbb);
  builder_.add_frame(frame);
  builder_.add_pY(pY);
  builder_.add_pX(pX);
  builder_.add_offset(offset);
  builder_.add_scale(scale);
  builder_.add_name(name);
  return builder_.Finish();
}

struct Timeline_Frame FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const flatbuffers::String *event() const { return GetPointer<const flatbuffers::String *>(4); }
  const flatbuffers::String *sound() const { return GetPointer<const flatbuffers::String *>(6); }
  const flatbuffers::String *action() const { return GetPointer<const flatbuffers::String *>(8); }
  const flatbuffers::String *tweenEasing() const { return GetPointer<const flatbuffers::String *>(10); }
  float z() const { return GetField<float>(12, 0.0); }
  uint32_t tweenRotate() const { return GetField<uint32_t>(14, 0); }
  uint16_t duration() const { return GetField<uint16_t>(16, 0); }
  int16_t displayIndex() const { return GetField<int16_t>(18, 0); }
  uint8_t hide() const { return GetField<uint8_t>(20, 0); }
  const Transform *transform() const { return GetStruct<const Transform *>(22); }
  const ColorTransform *colorTransform() const { return GetStruct<const ColorTransform *>(24); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* event */) &&
           verifier.Verify(event()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 6 /* sound */) &&
           verifier.Verify(sound()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 8 /* action */) &&
           verifier.Verify(action()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 10 /* tweenEasing */) &&
           verifier.Verify(tweenEasing()) &&
           VerifyField<float>(verifier, 12 /* z */) &&
           VerifyField<uint32_t>(verifier, 14 /* tweenRotate */) &&
           VerifyField<uint16_t>(verifier, 16 /* duration */) &&
           VerifyField<int16_t>(verifier, 18 /* displayIndex */) &&
           VerifyField<uint8_t>(verifier, 20 /* hide */) &&
           VerifyField<Transform>(verifier, 22 /* transform */) &&
           VerifyField<ColorTransform>(verifier, 24 /* colorTransform */) &&
           verifier.EndTable();
  }
};

struct Timeline_FrameBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_event(flatbuffers::Offset<flatbuffers::String> event) { fbb_.AddOffset(4, event); }
  void add_sound(flatbuffers::Offset<flatbuffers::String> sound) { fbb_.AddOffset(6, sound); }
  void add_action(flatbuffers::Offset<flatbuffers::String> action) { fbb_.AddOffset(8, action); }
  void add_tweenEasing(flatbuffers::Offset<flatbuffers::String> tweenEasing) { fbb_.AddOffset(10, tweenEasing); }
  void add_z(float z) { fbb_.AddElement<float>(12, z, 0.0); }
  void add_tweenRotate(uint32_t tweenRotate) { fbb_.AddElement<uint32_t>(14, tweenRotate, 0); }
  void add_duration(uint16_t duration) { fbb_.AddElement<uint16_t>(16, duration, 0); }
  void add_displayIndex(int16_t displayIndex) { fbb_.AddElement<int16_t>(18, displayIndex, 0); }
  void add_hide(uint8_t hide) { fbb_.AddElement<uint8_t>(20, hide, 0); }
  void add_transform(const Transform *transform) { fbb_.AddStruct(22, transform); }
  void add_colorTransform(const ColorTransform *colorTransform) { fbb_.AddStruct(24, colorTransform); }
  Timeline_FrameBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  Timeline_FrameBuilder &operator=(const Timeline_FrameBuilder &);
  flatbuffers::Offset<Timeline_Frame> Finish() {
    auto o = flatbuffers::Offset<Timeline_Frame>(fbb_.EndTable(start_, 11));
    return o;
  }
};

inline flatbuffers::Offset<Timeline_Frame> CreateTimeline_Frame(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<flatbuffers::String> event = 0,
   flatbuffers::Offset<flatbuffers::String> sound = 0,
   flatbuffers::Offset<flatbuffers::String> action = 0,
   flatbuffers::Offset<flatbuffers::String> tweenEasing = 0,
   float z = 0.0,
   uint32_t tweenRotate = 0,
   uint16_t duration = 0,
   int16_t displayIndex = 0,
   uint8_t hide = 0,
   const Transform *transform = 0,
   const ColorTransform *colorTransform = 0) {
  Timeline_FrameBuilder builder_(_fbb);
  builder_.add_colorTransform(colorTransform);
  builder_.add_transform(transform);
  builder_.add_tweenRotate(tweenRotate);
  builder_.add_z(z);
  builder_.add_tweenEasing(tweenEasing);
  builder_.add_action(action);
  builder_.add_sound(sound);
  builder_.add_event(event);
  builder_.add_displayIndex(displayIndex);
  builder_.add_duration(duration);
  builder_.add_hide(hide);
  return builder_.Finish();
}

inline const Dragonbones *GetDragonbones(const void *buf) { return flatbuffers::GetRoot<Dragonbones>(buf); }

inline bool VerifyDragonbonesBuffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<Dragonbones>(); }

inline void FinishDragonbonesBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<Dragonbones> root) { fbb.Finish(root); }

}  // namespace flatbuffers

#endif  // FLATBUFFERS_GENERATED_DRAGONBONES_FLATBUFFERS_H_

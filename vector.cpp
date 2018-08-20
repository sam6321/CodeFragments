template<typename scalar_t> constexpr Vec3_t<scalar_t> Vec3_t<scalar_t>::perpendicular() const {
    auto absVec = this->absolute();

    uint8 uyx = std::signbit(absVec.x - absVec.y);
    uint8 uzx = std::signbit(absVec.x - absVec.z);
    uint8 uzy = std::signbit(absVec.y - absVec.z);

    uint8 xm = uyx & uzx;
    uint8 ym = (1^xm) & uzy;
    uint8 zm = 1^(xm | ym);

    return this->cross(Vec3_t{xm, ym, zm});
}
idf_component_register(
    SRCS "src/ebsp.c"  # ✅ 显式列出文件
    SRCS "src/ebsp_led.c"
    INCLUDE_DIRS "inc"     # ✅ 正确路径（相对于当前文件）
    REQUIRES driver        # ✅ 声明依赖
    REQUIRES common_headers
)
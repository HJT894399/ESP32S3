idf_component_register(SRCS "src/i2c0.c"
                    REQUIRES common_headers
                    INCLUDE_DIRS "inc"     # ✅ 正确路径（相对于当前文件）
                    REQUIRES driver        # ✅ 声明依赖
                    )

.PHONY: clean All

All:
	@echo "----------Building project:[ PruebaArbol - Debug ]----------"
	@cd "PruebaArbol" && "$(MAKE)" -f  "PruebaArbol.mk"
clean:
	@echo "----------Cleaning project:[ PruebaArbol - Debug ]----------"
	@cd "PruebaArbol" && "$(MAKE)" -f  "PruebaArbol.mk" clean

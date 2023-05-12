PROJECT_DIR = .
A = $(notdir $(wildcard $(PROJECT_DIR)/*.c))

print-%:
	@echo $($(subst print-,,$@))
# crab

When you tend to forget what should you run `cabal` or `cargo`

```shell
#!/usr/bin/env sh

for f in *; do
  if [[ -f "${f}" ]]; then
    if [[ "${f}" == "Cargo.toml" ]]; then
      cargo "$@"
    fi
    if [[ "${f}" == *.cabal ]]; then
      cabal "$@"
    fi
  fi
done
```
